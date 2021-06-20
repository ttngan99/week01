#include<stdio.h>
#include <string.h>
#include <stdlib.h>

unsigned char base64[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/', '=' };
// chuyen doi bang ma
/*void conver_ascii()
{
	int   ascii['z' - '+']; //79
	size_t i;

	memset(inv, -1, sizeof(ascii));
	for (i=0; i<sizeof(base64)-1; i++) 
		ascii[base64[i]-43] = i;
}
*/
int ascii[] = { 62, -1, -1, -1, 63, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, -1, -1, -1, -1, -1, -1, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, -1, -1, -1, -1, -1, -1, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51 };
//size chuoi ma khi ma hoa
size_t encode_size(size_t inlen)
{
	size_t size;
	size = inlen;
	if (size % 3 != 0)
		size += 3 - (inlen % 3);
	size= size/3*4;
	return size;
}
//size giai ma
size_t decode_size(const char *inlen){
	size_t len = strlen(inlen) ;
	size_t size;
	size_t i;
	if(inlen == NULL) return 0;
	size = len/4*3;
	i=len;
	while(inlen[i] == '='){
		i--;
		size--;
	}
	return size;
}

int chuyenMa( char c){
	for(int i = 0; i < 64; i++)
		if(c == base64[i])
			return i;
}

char *encode(unsigned char *input, size_t len){
	
	char* output;

	size_t  output_len;
	output_len = encode_size(len);
	size_t i;
	size_t j;
	size_t v;
	if(input == NULL || len == 0) return NULL;
	output = (char*)malloc(output_len+1);
	output[output_len] = '\0'; 
	for (i=0, j=0; i<len ; i+=3, j+=4){
		v = input[i];
		v = i+1 < len ? v<<8 | input[i+1] : v<<8;
		v = i+2 < len ? v<<8 | input[i+2] : v<<8;
		
		output[j] = base64[(v >> 18) & 63];
		output[j+1] = base64[(v>>12) & 63];
		if(i+1 < len)
			output[j+2] = base64[(v>>6) & 63];
		else 
			output[j+2] = '=';
		if(i+2 < len )
			output[j+3] = base64[v & 63];
		else output[j+3] = '=';
	}
	return output;
}
bool kt_base64(char c){
	for (int i = 0; i<64 ; i++)
		if(c == base64[i])
			return true;
	return false;
}
int decode(const char *in, unsigned char *out, size_t outlen)
{
	size_t len;
	size_t i;
	size_t j;
	int    v;
	len = strlen(in);
	if (in == NULL || out == NULL)	return 0;


	if (outlen < decode_size(in) || len % 4 != 0)
		return 0;

	for (i=0; i<len; i++) 
		if (!kt_base64(in[i])) 	return 0;
	

	for (i=0, j=0; i<len; i+=4, j+=3) {
		v = ascii[in[i]-43];
		v = (v << 6) | ascii[in[i+1]-43];
		v = in[i+2]=='=' ? v << 6 : (v << 6) | ascii[in[i+2]-43];
		v = in[i+3]=='=' ? v << 6 : (v << 6) | ascii[in[i+3]-43];

		out[j] = (v >> 16) & 255;
		if (in[i+2] != '=')
			out[j+1] = (v >> 8) & 255;
		if (in[i+3] != '=')
			out[j+2] = v & 255;
	}

	return 1;
}
int main() {
	
	
	const char *c ="I have binary data in an unsigned char variable. I need to convert them to PEM base64 in c. I looked in openssl library but i could not find any function. Does any body have any idea?";
	printf("\n %d", strlen(c));
	printf("\n %d", encode_size(strlen(c)));
	printf("\n out %d", decode_size(c));
	char *out;
	char *de_out;
	out = encode((unsigned char *)c, strlen(c));
	printf("\n encoding: \n '%s'\n", out);
	size_t size;
	size = decode_size(out);
	de_out = (char*) malloc (size );
	
	decode ( out,(unsigned char *) de_out, size );
	de_out[size] = '\0';
	printf("\n decoding:   \n  '%s'\n", de_out);
//	printf( " %c" , ascii['C'-43] );
//	printf("%d",'z'-'+');
	free(de_out);
	return 0;
}
