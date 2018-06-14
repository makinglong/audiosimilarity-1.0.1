/* audio_similarity.c
*
*  Copyright (c) 2018 The  project authors. All Rights Reserved.
*  Function: counting audio and voice similarity with audio_dsym,
*  audio_dasym and predict features (average compensation feature,
*  spectral gain_modulate feature,neteq feature and so on.)
*  Date   :2018-2-12
*  Version: v1.0.0.1
*
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "../include/audio_similarity.h"

#if 1
void usage(void) {
	printf("Usage:\n");
	printf(" AS HELP               Displays this text\n");
	printf(" AS [options] ref deg\n");
	printf(" Run model on reference ref and degraded deg\n");
	printf("\n");
}

int days = 0;
int months = 0;

void getNowTime()
{
	time_t timer;
	struct tm *tblock;
	timer = time(NULL);
	tblock = localtime(&timer);
	days = tblock->tm_mday;
	months = tblock->tm_mon;
	printf("Local time is: %s\n", asctime(tblock));
}

int main(int argc, const char *argv[])
{
	SYSTEMTIME sys;
	argv[1] = "E:\\project\\audiosimilarity-1.0.1\\audiosimilarity\\audiosimilarity\\Debug\\20180604230304.wav";
	argv[2] = "E:\\project\\audiosimilarity-1.0.1\\audiosimilarity\\audiosimilarity\\Debug\\20180604230331.wav";
	//const char *fp_ref = "E:\\project\\audiosimilarity-1.0.1\\audiosimilarity\\audiosimilarity\\Debug\\Audio.wav";
	//const char *fp_input = "E:\\project\\audiosimilarity-1.0.1\\audiosimilarity\\audiosimilarity\\Debug\\record3.wav";
	const char *fp_ref = argv[1];
	const char *fp_input = argv[2];
	int result = 0;
	int sample_rate = 16000;
	float sensitivity = 0.5f;
	//int sample_rate = atoi(argv[3]);    //sample rate
	//double as_score = 0;
	char score[32];

	getNowTime();

	printf("days is %d , month is %d \n", days, months);

	result = AudioSimilarity_Start();
	if (result < 0)
	{
		printf("AudioSimilarity_Start is failed!\n");
	}

	//if (days < 16 && months < 5)

	GetLocalTime(&sys);
	printf("%s %d %s: %4d/%02d/%02d %02d:%02d:%02d.%03d week:%1d\n", __FILE__, __LINE__, __FUNCTION__, sys.wYear, sys.wMonth, sys.wDay, sys.wHour, sys.wMinute, sys.wSecond, sys.wMilliseconds, sys.wDayOfWeek);
	if (1)
	{
		//result = AudioSimilarity_Process(fp_ref, fp_input, sample_rate, &as_score);
		result = AudioSimilarity_Process(fp_ref, fp_input, sample_rate, sensitivity, &score);
		//result = AudioSimilarity_Process(fp_ref, fp_input, sample_rate);
	}
	else
	{
		printf("Please contact to author, thank you! telephone number:13471251858 \n");
	}

	GetLocalTime(&sys);
	printf("%s %d %s: %4d/%02d/%02d %02d:%02d:%02d.%03d week:%1d\n", __FILE__, __LINE__, __FUNCTION__, sys.wYear, sys.wMonth, sys.wDay, sys.wHour, sys.wMinute, sys.wSecond, sys.wMilliseconds, sys.wDayOfWeek);

	if (result < 0)
	{
		printf("AudioSimilarity_process is failed!\n");
	}
	else
	{
		//printf("AudioSimilarity_process audio similarity score is %.3f \n",as_score);
		printf("AudioSimilarity_process audio similarity score is %s \n", score);
	}

	result = AudioSimilarity_Destory();
	if (result < 0)
	{
		printf("AudioSimilarity_Destory is failed!\n");
	}

	printf("请输入任意字符：\n");
	getchar();

	return 0;

}

#else
extern "C"  _declspec(dllexport)int AudioSimilarity_Process_dll(char *RefFile, char *DeFile, int SampleRate, char *OutSimilarityScore)
{
	int result = 0;
	result = AudioSimilarity_Process(RefFile, DeFile, SampleRate, OutSimilarityScore);
	return 0;
}


#ifndef _DLLMAIN_H    
#define _DLLMAIN_H    
#ifndef        DLL_EXPORT    
#define _LIBAPI __declspec(dllexport)    
#else    
#define _LIBAPI __declspec(dllimport)    
#endif    
#ifdef __cplusplus  
extern "C" {
#endif  
	_LIBAPI int AudioSimilarity_Process_dll(char *RefFile, char *DeFile, int SampleRate, char *OutSimilarityScore)
	{
		int result = 0;
		result = AudioSimilarity_Process(RefFile, DeFile, SampleRate, OutSimilarityScore);
		return 0;
	}
#ifdef __cplusplus  
}
#endif  
#endif /* _DLL_H_ */ 

#endif