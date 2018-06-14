/* audio_similarity.h
*
*  Copyright (c) 2018 The  project authors. All Rights Reserved.
*  Function: counting audio and voice similarity with audio_dsym,
*  audio_dasym and predict features (average compensation feature,
*  spectral gain_modulate feature,neteq feature and so on.)
*  Date   :2018-2-12
*  Version: v1.0.0.1
*
*/

#ifndef AUDIO_SIMILARITY_H_
#define AUDIO_SIMILARITY_H_

#if 1

#ifndef        DLL_EXPORT    
#define _LIBAPI __declspec(dllexport)    
#else    
#define _LIBAPI __declspec(dllimport)    
#endif 

#ifdef __cplusplus
extern "C" {
#endif

	/*
	* This function start and init AudioSimilarity
	*
	*
	* Return value         :  0 - Ok
	*                        -1 - Error
	*/
	_LIBAPI int AudioSimilarity_Start();


	/*
	* This function frees the dynamic memory of AudioSimilarity
	*
	*
	* Return value         :  0 - Ok
	*                        -1 - Error
	*/
	_LIBAPI int AudioSimilarity_Destory();


	/*
	* This functions do score of similiarity audio for the audio file. The
	* input and output signals should always be 16KHz/8KHz and 16bits.
	*
	* Input
	*      - pRefFile       : reference audio file.
	*      - pDeFile        : waiting process audio file
	*      - pSampleRate    : sample rate 8K/16K
	*      - pSensitivity   : sensitivity(0~1)
	*
	* Output:
	*      - pOutSimilarityScore : output similarity score
	*
	* Return value         :  0 - OK
	*                        -1 - Error
	*/

	_LIBAPI int AudioSimilarity_Process(const char *pRefFile, const char *pDeFile, int pSampleRate, float pSensitivity, char *pOutSimilarityScore);
	//_LIBAPI int AudioSimilarity_Process(const char *pRefFile, const char *pDeFile, int pSampleRate);


#ifdef __cplusplus
}
#endif
#else

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

#endif  // AUDIO_SIMILARITY_H_
