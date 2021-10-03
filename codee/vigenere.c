//including standard library

#include<stdio.h>
#include<string.h>

//initial key

char key[] = "SDLC"; 
int i, j,count = 0;

void vigenere()
{
char msg[] = "tE SDLC applied SDLC the larsen and toubro ,";
char msgchk[] ="tE SDLC applied SDLC the larsen and toubro ,";
int msgLen = strlen(msg), keyLen = strlen(key);
char newKey[msgLen], encryptedMsg[msgLen], decryptedMsg[msgLen];

printf("Original Message: %s", msg);

//checking whether message is lower case and changing into upper 
//case to maitain the uniformity

for(int i=0;i<=msgLen;i++)
{

    if(msg[i]>=97&&msg[i]<=122)
    {                           
        msg[i]=msg[i]-32;
    }

}


//generating new key of the length equal to message string
//using cyclic method
for(i = 0, j = 0; i < msgLen; ++i, ++j)
{

    if(j == keyLen) 
    {
        j = 0;
    }
    newKey[i] = key[j];   

}
newKey[i] = '\0';

//encryption of the string
//adding input string with the new key generated
//and mod 26 is applied and converted into upper case 
//with the space 
for(i = 0; i < msgLen; ++i)
{

    if(msgchk[i]==' ')
    {
        encryptedMsg[i] = ' ';  
    }                                                        
    else 
    {
        encryptedMsg[i] = ((msg[i] + newKey[i]) % 26) + 65;
    }
     
}

encryptedMsg[i] = '\0';
printf("\nEncrypted Message: %s", encryptedMsg);

//decrypting the encrypted string
//subtracting the encrypted code with the new key
//and mod 26 is applied to get the decrypted string 
//the decrypted string will be same as input message string

for(i=0; i < msgLen;i++)
{

    if(msgchk[i]>=65&&msgchk[i]<=90)
    {
        decryptedMsg[i] = (((encryptedMsg[i] - newKey[i]) + 26) % 26) + 65;
    }                                                                       
    else if(msgchk[i]==' ')
    {
        decryptedMsg[i] =' ';
    }
    else if(msgchk[i]>=97&&msgchk[i]<=122)
    {
        decryptedMsg[i] = (((encryptedMsg[i] - newKey[i]) + 26) % 26) +97;
    }
    else
    {
        decryptedMsg[i]=msgchk[i];
    }

}

                                                                      
decryptedMsg[i] = '\0';
printf("\nDecrypted Message: %s", decryptedMsg);
}

int main()
{
    vigenere();   
    return 0;
}