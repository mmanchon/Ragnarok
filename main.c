/**
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FileUtilities.h"

int main(int argc, char **argv) {
    int fd = 0;
    int systemType = 0;
    FileSystem fileSystem;
    //Dir_info dir;

    if (!argc) {
        printf(ARGUMENTS_NUMBER);

    } else {

        if (memcmp(argv[1], "-info", sizeof(char) * strlen(argv[1])) == 0) {
            fd = exisitsFile(argv[2]);
            systemType = detectFileSystemType(fd);

            if (systemType == 1) {
                fileSystem = initSearchInfoExt4(fileSystem);

            } else if (systemType == 2) {
                fileSystem = initSearchInfoFat32(fileSystem);

            }else{
                printf(NOT_FOUND);
            }
        } else if (memcmp(argv[1], "-search", sizeof(char) * strlen(argv[1])) == 0) {

            if (argc != 4) {
                printf(ARGUMENTS_NUMBER);

            } else {
                fd = exisitsFile(argv[2]);
                systemType = detectFileSystemType(fd);

                if (systemType == 1) {
                    searchFileExt4(argv[3]);

                } else if (systemType == 2) {
                    fileSystem = searchFileFat32(fileSystem, argv[3]);
                }else{
                    printf(NOT_FOUND);
                }
            }
        }else if (memcmp(argv[1], "-show", sizeof(char) * strlen(argv[1])) == 0){

            if(argc != 4){
                printf(ARGUMENTS_NUMBER);

            }else{
                fd = exisitsFile(argv[2]);
                systemType = detectFileSystemType(fd);

                if (systemType == 1) {
                    searchFileExt4(argv[3]);

                } else if (systemType == 2) {

                }else{
                    printf(NOT_FOUND);
                }
            }
        }
    }

    return 0;
}