//this program generates the zig zag tranposition cipher for a given plaintext message
//it also displays the grid and transposed grid before encrypting

#include<stdio.h>
#include<string.h>
void encryptMsg(char msg[], int key){
    int n = strlen(msg), i, j, k = -1, row = 0, col = 0;
    char zig[key][n];
    printf("GRID: \n");
    for(i = 0; i < key; i++){
	
        for(j = 0; j < n; j++) {
        	zig[i][j] = '*';
        	printf("%3c",zig[i][j]);
		}
		printf("\n"); 
    } 
	for(i = 0; i < n; i++){
        zig[row][col] = msg[i];
        col++;
 		if(row == 0 || row == key-1)   //change sign of k if row is first or last
            k= k * (-1);
 			row += k; //k can be 1 or -1
    }
    printf("Transposed Grid :\n");
    for(i = 0; i < key; i++){
        for(j = 0; j < n; j++){
		if(zig[i][j] == '*')
        printf("%3c",'*');
        else if(zig[i][j] == ' ')
        printf("%3c",'_');
        else
        printf("%3c",zig[i][j]); //put message on the grid
    }
    printf("\n");
}
    printf("\nEncrypted Message: ");
	for(i = 0; i < key; ++i){
        for(j = 0; j < n; ++j){
        	if(zig[i][j] != '*')
            printf("%c", zig[i][j]);
		}
	}
            
}
void decryptMsg(char enMsg[], int key){
    int len = strlen(enMsg), i, j, k = -1, row = 0, col = 0, m = 0;
    char zig[key][len];
 
    for(i = 0; i < key; ++i){
        for(j = 0; j < len; ++j)
            zig[i][j] = '\n';}
 
    for(i = 0; i < len; ++i){
        zig[row][col++] = '*';
 
        if(row == 0 || row == key-1)
            k= k * (-1);
 
        row = row + k;
    }
 
    for(i = 0; i < key; ++i){
        for(j = 0; j < len; ++j){
            if(zig[i][j] == '*')
                zig[i][j] = enMsg[m++];}
	}
    row = col = 0;
    k = -1;
 
    printf("\nDecrypted Message: ");
 
    for(i = 0; i < len; ++i){
        printf("%c", zig[row][col++]);
 
        if(row == 0 || row == key-1)
            k= k * (-1);
 
        row = row + k;
    }
}

int main(){
	char txt[60];
	char enc[60];
	int key,r;
	printf("ZIG ZAG ENCRYPTION\n Enter the Text to be encrypted:\n");
	gets(txt); 
	printf("Enter the KEY :\n");
	scanf("%d",&key);
	fflush(stdin);
	encryptMsg(txt,key);
	printf("\nEnter message to decrypt:\n");
	gets(enc);
	decryptMsg(enc,key);
	return 0;
}
