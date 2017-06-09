#include<stdio.h>

int j = 0;
int array[500][3];
int i = 0;

int main()
{
    readFile();    //Read file and compute address
	printArray();  //print results
	printf("***DONE***\n");
    return 0;
}

int readFile(){

	FILE *ptr_file;    //pointer for the file
    char buf[1000];     //char array to store the read string
    			
    ptr_file =fopen("input.txt","r");
    if (!ptr_file)
        return 1;

    while (fgets(buf,1000, ptr_file)!=NULL){
    	array[i][0] = atoi(buf);      //Convert the read string into an int and store
    	computeAddress(array[i][0], i);    //pass the read value and the index, then compute the address and page
        i++; 		//keep track of the index of the virtual address
    }

	fclose(ptr_file);    
	return 0;
}

int printArray(){
	//print some stuff
	printf("Virtual Address, Page Number, Physical Address\n");
	for(j = 0;j<i;j++){
		printf("%i, %i, %i\n",array[j][0],array[j][1],array[j][2]);
	}
	return 0;
}

int computeAddress(int vAddress,int index){
	//this method translates a virtual address into a page and a physical address
	//the results are stored in the global array at the specific index
	int page = vAddress; 
	int offset = vAddress;

	page = page >> 12;  //shift bits by 12 because the page size is 12 bits
	
	offset = offset & 0x1FFF; //find the offset
	
	array[index][1] = page;   //save out the page

	array[index][2] = offset; //save out the offset

	return 0; 
}

	
	