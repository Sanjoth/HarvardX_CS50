/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */

#include <stdio.h>
#include <cs50.h>
#include <stdint.h>

/**
* define a struct with the size of the signature (4 bytes) 
*/ 
typedef uint8_t BYTE;

/**
* define the SIGNATURE of a section of 512 bytes
*/ 
typedef struct
{
    BYTE zero;
    BYTE one;
    BYTE two;
    BYTE three;
}
SIGNATURE;

int main(void)
{
    // open the card file
    FILE* card = fopen("card.raw", "r");
    if(card == NULL)
    {
        fclose(card);
        fprintf(stderr, "Could not read from card file\n");
        return 1;
    }

    // file signature of the section of 512 bytes
    SIGNATURE sectionSig;

    // the current jpg file to write jpg data on
    FILE* jpgFile;
    
    char buffer[508];
    int jpgCount = 0;

    // tells if we've started collecting jpgs
    bool foundJpg = false;

    // do for each section of bytes (buffer)
    while(fread(&sectionSig, sizeof(SIGNATURE), 1, card) > 0)
    {
        char* jpgName = malloc(sizeof(char) * 8);

        // read the rest of the section of 512 bytes into the buffer
        fread(&buffer, 508, 1, card);

        // check for the start of jpg
        if(sectionSig.zero == 0xff && sectionSig.one == 0xd8 &&
            sectionSig.two == 0xff && (sectionSig.three == 0xe0 ||
            sectionSig.three == 0xe1))
        {
            foundJpg = true;
            
            // close the file, if writing to one previously
            if(jpgCount != 0)
                fclose(jpgFile);

            // try to open a jpg file named ###.jpg
            sprintf(jpgName, "%03d.jpg", jpgCount++);
            jpgFile = fopen(jpgName, "w");
            if(jpgFile == NULL)
            {
                fclose(jpgFile);
                fprintf(stderr, "Could not write %s.jpg\n", jpgName);
                return 2;
            }

            // write the first 4 bytes
            fwrite(&sectionSig, sizeof(SIGNATURE), 1, jpgFile);
            // write the next 508 bytes of the section
            fwrite(&buffer, 508, 1, jpgFile);
        }
        // if jpg found and at the end of the photos?
        else if(foundJpg && jpgCount <= 51)
        {
            // recreate name of the jpg file
            sprintf(jpgName, "%03d.jpg", jpgCount);

            if(jpgFile == NULL)
            {
                fclose(jpgFile);
                fprintf(stderr, "Could not write %s\n", jpgName);
                return 3;
            }
            
            // write all 512 bytes to the file under jpgName
            fwrite(&sectionSig, sizeof(SIGNATURE), 1, jpgFile);
            fwrite(&buffer, 508, 1, jpgFile);
        }

        // free mem for jpgName string
        free(jpgName);
    }
    // ensure the last jpg is closed
    fclose(jpgFile);

    // close the mem card file
    fclose(card);
}
