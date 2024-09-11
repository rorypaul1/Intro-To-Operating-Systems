#include <unistd.h>

/* Unix Way
int main(int argc, char *argv[]) {
    // creates file
    int file = open("/tmp/file", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);  
    char buffer[40];
    sprintf(buffer, "I will persist!\n");
    //writes data to file
    write(file, buffer, strlen(buffer));
    //fsync(file); //Makes sure data is physically written to operating system
    _commit(file); //fsync is a unix command so we need a windows equivalent
    // closes the file
    close(file);  
    return 0;
}
*/

#include <stdio.h>

int main() {
    // Declare a file pointer
    FILE *file;

    // Open the file for writing (w mode)
    file = fopen("tmp.txt", "w");

    // Check if the file was created successfully
    if (file == NULL) {
        printf("Error: Could not create file.\n");
        return 1; // Return an error code
    }

    // Write some text to the file
    fprintf(file, "I will persist!\n");
    fprintf(file, "This is a test file created using C.\n");

    // Close the file
    fclose(file);

    printf("File created and text written successfully.\n");

    return 0;
}