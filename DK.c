#include <stdio.h>
#include <string.h>


typedef struct CtSize
{
    int width;
    int height;
} CtSize;

typedef struct CtRect
{
	int x; 
	int y;
	int width;
	int height;
} CtRect;

typedef struct CvTag
{
	unsigned char Type;
	int x;
	int y;
	int width;
	int height;
} CvTag;

typedef struct CvSetExamData
{
	char Name[10];
	CtSize imgSize;
	CtRect ScanROI;
	CvTag Tag[10];
	int TagNum;
} CvSetExamData;

void ExampleDataSetMaker(char *name);

int main(int argc, char *argv[])
{
   //ExampleExaminatorMaker("DK001.dk");
   ExampleDataSetMaker("DK002.dkdk");
   return; 
   FILE *file1;
   FILE *file2;
   FILE *file3;
   char buf;
   char strtmp[15];
   CvSetExamData ExampleSet;
   
   //Open uploaded setting data
   file1 = fopen( argv[1], "rb" );
   //Read ExamSet Data
   fread(&ExampleSet,sizeof(struct CvSetExamData),1,file1);
   //Test ExampleSet.Tag[2].y = 300;
   if(ExampleSet.Tag[2].y==300)
       printf("%s\n", "You got it! DKDK");
   
   //Close setting data file
   fclose(file1);

   ///Read examinator and save it as name.dkdk.dk///
   file2 = fopen( "Examinator.dk", "rb" );
   
   strcpy (strtmp,argv[1]);
   strcat (strtmp,".dk");

   file3 = fopen( strtmp, "wb" );
   while(1){
	    //fread讀取
   	    fread(&buf,1,1,file2);
	    if(feof(file2)) break;
	    fwrite(&buf, 1, 1, file3);
   }

   fclose(file3);

   return 0; 
}

void ExampleDataSetMaker(char *name)
{
	CvSetExamData ExampleSet;
	memset(&ExampleSet,0,sizeof(CvSetExamData)); // add by Wonda 0117 
	FILE *ptr_myfile;
	strcpy(ExampleSet.Name, name);
	ExampleSet.imgSize.width = 640;
	ExampleSet.imgSize.height = 480;
	ExampleSet.ScanROI.x = 174;
	ExampleSet.ScanROI.y = 2;
	ExampleSet.ScanROI.width = 544-174;
	ExampleSet.ScanROI.height = 463;
	ExampleSet.Tag[0].x = 253;
	ExampleSet.Tag[0].y = 38;
	ExampleSet.Tag[0].width = 96;
	ExampleSet.Tag[0].height = 60;
	ExampleSet.Tag[1].x = 351;
	ExampleSet.Tag[1].y = 271;
	ExampleSet.Tag[1].width = 66;
	ExampleSet.Tag[1].height = 33;
	ExampleSet.Tag[2].x = 473;
	ExampleSet.Tag[2].y = 300;
	ExampleSet.Tag[2].width = 45;
	ExampleSet.Tag[2].height = 70;
	ExampleSet.TagNum = 3;  // add by Wonda 0117 

	ptr_myfile=fopen(name,"wb");
	if (!ptr_myfile)
	{
		printf("Unable to open file!");
		return;
	}

	//Write Header
	fwrite(&ExampleSet, sizeof(struct CvSetExamData), 1, ptr_myfile);
	fclose(ptr_myfile);
}
