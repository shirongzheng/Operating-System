/*
 CSC33200   Task 3
 
 Shirong Zheng      03/23/2018

Part 3: Step 2. Copy the contents of source.txt1 into destination1.txt 
	and destination2.txt as per the following procedure.
	1. Read the next 100 characters from source.txt, and among characters read, 
		replace each char- acter ’1’ with character ’A’ and all characters are 
		then written in destination1.txt
	2. Then the next 50 characters are read from source.txt, and among characters 
		read, replace each character ’2’ with character ’B’ and all characters are 
		then written in destination2.txt.
	3. The previous steps are repeated until the end of file source.txt. The last 
		read may not have 100 or 50 characters.
*/


#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

int main(void)
{
	int source, rd, acs, dest1, dest2;

	source = open("source.txt", O_RDONLY); 

	dest1 = open("destination1.txt", O_CREAT | O_RDWR, S_IRWXU);  
	dest2 = open("destination2.txt", O_CREAT | O_RDWR, S_IRWXU);

	if (source == -1 && dest1 == -1 && dest2 == -1)
	{
		printf("Error: [%s]\n", strerror(errno));
	}
	else{
		char buf[101];	//An array of chars size n which is 101 to read 100 chars.
		int n = 101;

		while ( (rd = read(source, buf, n)) > 0){

			if (n == 101) {

				for (int i = 0; i < sizeof(buf); i++){
                    // First 100 characters, replace "1" with 'A' in destination1 file.
					if (buf[i] == '1')		
						buf[i] = 'A';

				}
				write(dest1, buf, rd);

				n = 51;	// Change n to 51.
			}
			else{

				for (int i = 0; i < sizeof(buf); i++){
                    // Next 50 characters, replace "2" with 'B' in destination2 file.
					if (buf[i] == '2')
						buf[i] = 'B';
				}
				write(dest2, buf, rd);
				n = 101;
			}
		}

	}	

	close(source);
	close(dest1);
	close(dest2);

	return 0;

}
