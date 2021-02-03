#include <stdio.h>
//#include "indenter.h"

void printModifiedPath(const char* path)
{
	int d =0;
	while(path[d] != '.')
		d++;

	char newPath[128];

	sprintf("newpath", "%. *s_indented.c",d, path);

	printf("%s\n", newPath);
}

void removeSpaces()
{
	FILE* infile = fopen("input.txt", "r");
	
	if(infile == NULL)
	{
		printf("Error opening input.txt\n");
		fclose(infile);
	}

	FILE* outfile = fopen("output.txt", "w");
	
	if(outfile == NULL)
	{
		printf("Error opening output.txt");
		fclose(outfile);
	}

	char c;
	int spaceWritten = 0;

	while((c = fgetc(infile)) !=EOF)
	{
		switch(c)
		{
			case '\t':

			case ' ':
			{
				if(!spaceWritten)
				{
					fputc(' ',outfile);
				}
				break;
			}
			case '{':
			{
				if(!spaceWritten)
				{
					fputc('\t',outfile);
				}
				break;
			}
			case '}':
			{
				if(!spaceWritten)
				{
					fputc('\n',outfile);
				}
				break;
			}
			case '\n':
			{
				if(spaceWritten)
					fputc('\t',outfile);
				break;
			}
			default:
			{
				fputc(c , outfile);
				spaceWritten = 0;
			}
			

		}
	}


	fclose(infile);
	fclose(outfile);
}


int main(){

const char* paths[] = {
	"source1.c",
	"source2.cpp",
	"source3.c",
	};

	removeSpaces();

	int i;
	for(i=0; i<sizeof(paths)/sizeof(char*); i++)
	{
		printf("File at %s was%s successfully indented.\n", paths[i], indenter(paths[i])?"":" not");
	}
}