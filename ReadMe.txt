

/***For Model File .dkdk.dk***/
Header:
CvExamData

Body:
Tables' Parameters

PS: .BIN can be changed to other names in the future -> Ex: .one

/**CvExamData Structure**/
typedef struct CvTag
{
	unsigned char Type;
	int x;
	int y;
	int width;
	int height;
} CvTag;

typedef struct CvExamData
{
	int ID;
	unsigned char *img;
	CtSize imgSize;
	CtRect ScanROI;
	CvTag Tag[10];
	int DetectorSize[10];
	int TagNum;
} CvExamData;

/**Read Example**/
void main()
{
	FILE *ptr_myfile;
	CvExamData ExamData;
	double CascadeParaTable[500];

	ptr_myfile=fopen("Examinator.bin","rb");
	if (!ptr_myfile)
	{
		printf("Unable to open file!");
		return;
	}

	//Read ExamData (FileID, Tags Info, Number of Tables)
	fread(&(ExamData),sizeof(struct CvExamData),1,ptr_myfile);
	printf("%d\n",ExamData.ScanROI.y);

    //Load Tables & init detector
    int i;
	for(i=0; i<ExamData.TagNum; i++)
	{
		//Read Tables
		fread(CascadeParaTable,sizeof(double)*(ExamData.DetectorSize[i]),1,ptr_myfile);
		//Table -> Detector initialization here
	}
	
    fclose(ptr_myfile);   
}
