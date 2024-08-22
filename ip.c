#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void valeurCible(char *ip, int *bit1, int *bit2, int *bit3, int *bit4);
void changeType(int bit1, int bit2, int bit3, int bit4, int *premier_bits, int *deuxieme_bits, int *troisieme_bits, int *quatrieme_bits);
void infoIP(int bit1, int bit2, int bit3, int bit4);
void end();
void start();
int main() {
    char ip[200];
    int bit1, bit2, bit3, bit4;
    int premier_bits, deuxieme_bits, troisieme_bits, quatrieme_bits;
	char *data=NULL;
	printf("content-text: text/html\n\n");
	data=getenv("QUERY_STRING");
	if(data != NULL){
		sscanf(data, "ip=%s", ip);
	}
	
    valeurCible(ip, &bit1, &bit2, &bit3, &bit4);
    changeType(bit1, bit2, bit3, bit4, &premier_bits, &deuxieme_bits, &troisieme_bits, &quatrieme_bits);
    start();
	infoIP(premier_bits, deuxieme_bits, troisieme_bits, quatrieme_bits);
	end();
    return 0;
}
void start(){
	printf("<html><head>");
	printf("<style>span{font-size: 50px;font-family: Arial;}</style>");
	printf("</head><body>");
}
void end(){
	printf("</body></html>");
}
void valeurCible(char *ip, int *bit1, int *bit2, int *bit3, int *bit4) {
    char *token;
    token = strtok(ip, ".");
    *bit1 = atoi(token);
    token = strtok(NULL, ".");
    *bit2 = atoi(token);
    token = strtok(NULL, ".");
    *bit3 = atoi(token);
    token = strtok(NULL, ".");
    *bit4 = atoi(token);
}

void changeType(int bit1, int bit2, int bit3, int bit4, int *premier_bits, int *deuxieme_bits, int *troisieme_bits, int *quatrieme_bits) {
    *premier_bits = bit1;
    *deuxieme_bits = bit2;
    *troisieme_bits = bit3;
    *quatrieme_bits = bit4;
}

void infoIP(int bit1, int bit2, int bit3, int bit4) {
	int i=0, j, tab[9];
    if (bit1 >= 0 && bit1 <= 127) {
        if (bit2 >= 0 && bit2 <= 255) {
            if (bit3 >= 0 && bit3 <= 255) {
                if (bit4 >= 0 && bit4 <= 255) {
                printf("<center><span>Votre adresse IP est de classe A\n</span></center>");
                }
			}
        }
    }
    else if (bit1 >= 128 && bit1 <= 191) {
        if (bit2 >= 0 && bit2 <= 255) {
            if (bit3 >= 0 && bit3 <= 255) {
                if (bit4 >= 0 && bit4 <= 255) {
                    printf("<center><span>Votre adresse IP est de classe B\n</span></center>");
                }
            }
        }
    }
    else if (bit1 >= 192 && bit1 <= 223) {
        if (bit2 >= 0 && bit2 <= 255) {
            if (bit3 >= 0 && bit3 <= 255) {
                if (bit4 >= 0 && bit4 <= 255) {
                    printf("<center><span>Votre adresse IP est de classe C\n</span></center>");
                }
            }
        }
    }
    else if (bit1 >= 224 && bit1 <= 239) {
        if (bit2 >= 0 && bit2 <= 255) {
            if (bit3 >= 0 && bit3 <= 255) {
                if (bit4 >= 0 && bit4 <= 255) {
                    printf("</center><span>Votre adresse IP est de classe D\n</span></center>");
                }
            }
        }
    }
    else if (bit1 == 240) {
        if (bit2 >= 0 && bit2 <= 255) {
            if (bit3 >= 0 && bit3 <= 255) {
                if (bit4 >= 0 && bit4 <= 255) {
                    printf("<center><span>Votre adresse IP est de classe E\n</span></center>");
                }
            }
        }
    }
	else{
		printf("<form action=\"ip.html\"><center><span>Chaque chiffre doit entre 0 et 255</span></center>"
		"<input type=\"submit\" value=\"Resaisir\"></form>");
		
	}
}

