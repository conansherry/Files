#include "com_immomo_moaservice_impl_nearby_face_bean_KDTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <flann/flann.h>

JNIEXPORT jlong JNICALL Java_com_immomo_moaservice_impl_nearby_face_bean_KDTree_NativeInitParams
(JNIEnv *env, jobject obj)
{
	std::cout << "Java_momocv_KDTree_InitParams" << std::endl;
	FLANNParameters* p = new FLANNParameters(DEFAULT_FLANN_PARAMETERS);
	p->algorithm = FLANN_INDEX_KDTREE;
	p->trees = 8;
	p->log_level = FLANN_LOG_INFO;
	p->checks = 64;
	jlong ptr = reinterpret_cast<jlong>(p);
	return ptr;
}

JNIEXPORT jint JNICALL Java_com_immomo_moaservice_impl_nearby_face_bean_KDTree_NativeDestroyParams
(JNIEnv *env, jobject obj, jlong paramptr)
{
	std::cout << "Java_momocv_KDTree_DestroyParams" << std::endl;
	jint res = 0;
	FLANNParameters *p = reinterpret_cast<FLANNParameters *>(paramptr);
	if (p == NULL)
		return 1;
	delete p;
	return res;
}
:or_eq
JNIEXPORT jlong JNICALL Java_com_immomo_moaservice_impl_nearby_face_bean_KDTree_NativeInitBuffer
(JNIEnv *env, jobject obj, jlong bufsize)
{
	std::cout << "Java_momocv_KDTree_InitBuffer" << std::endl;
	float *buf = new float[bufsize];
	jlong ptr = reinterpret_cast<jlong>(buf);
	return ptr;
}

JNIEXPORT jint JNICALL Java_com_immomo_moaservice_impl_nearby_face_bean_KDTree_NativeDestroyBuffer
(JNIEnv *env, jobject obj, jlong bufptr)
{
	std::cout << "Java_momocv_KDTree_DestroyBuffer" << std::endl;
	jint res = 0;
	float *buf = reinterpret_cast<float *>(bufptr);
	if (buf == NULL)
		return 1;
	delete[] buf;
	return res;
}

JNIEXPORT jint JNICALL Java_com_immomo_moaservice_impl_nearby_face_bean_KDTree_NativeInsertData
(JNIEnv *env, jobject obj, jlong bufptr, jlong start, jfloatArray data)
{
	std::cout << "Java_momocv_KDTree_InsertData" << std::endl;
	jint res = 0;
	float *buf = reinterpret_cast<float *>(bufptr);
	if (buf == NULL)
		return 1;

	float *javadata = env->GetFloatArrayElements(data, NULL);
	jsize javadataSize = env->GetArrayLength(data);
	memcpy(buf + start, javadata, javadataSize);
	env->ReleaseFloatArrayElements(data, javadata, 0);

	return res;
}

JNIEXPORT jlong JNICALL Java_com_immomo_moaservice_impl_nearby_face_bean_KDTree_NativeBuildIndex
(JNIEnv *env, jobject obj, jlong bufptr, jlong paramptr, jlong count, jlong dim)
{
	std::cout << "Java_momocv_KDTree_BuildIndex" << std::endl;
	float speedup;
	flann_index_t index_id;
	float *buf = reinterpret_cast<float *>(bufptr);
	FLANNParameters *p = reinterpret_cast<FLANNParameters *>(paramptr);
	if (buf == NULL || p == NULL)
		return 0;
	index_id = flann_build_index(buf, count, dim, &speedup, p);
	jlong ptr = reinterpret_cast<jlong>(index_id);
	return ptr;
}

JNIEXPORT jint JNICALL Java_com_immomo_moaservice_impl_nearby_face_bean_KDTree_NativeDestroyIndex
(JNIEnv *env, jobject obj, jlong kdtreeptr, jlong paramptr)
{
	std::cout << "Java_momocv_KDTree_DestroyIndex" << std::endl;
	jint res = 0;
	flann_index_t kdtreeIndex = reinterpret_cast<flann_index_t>(kdtreeptr);
	FLANNParameters *p = reinterpret_cast<FLANNParameters *>(paramptr);
	if (kdtreeIndex == NULL || p == NULL)
		return 1;
	res = flann_free_index(kdtreeIndex, p);
	return res;
}

JNIEXPORT jintArray JNICALL Java_com_immomo_moaservice_impl_nearby_face_bean_KDTree_NativeSearchNearestNeighborsIndex
(JNIEnv *env, jobject obj, jlong kdtreeptr, jlong paramptr, jfloatArray searchdata, jlong count, jint nn)
{
	std::cout << "Java_momocv_KDTree_SearchNearestNeighborsIndex" << std::endl;
	jint res = 0;
	flann_index_t kdtreeIndex = reinterpret_cast<flann_index_t>(kdtreeptr);
	FLANNParameters *p = reinterpret_cast<FLANNParameters *>(paramptr);
	int* result = new int[count * nn];
	float* dists = new float[count * nn];
	float *testset = env->GetFloatArrayElements(searchdata, NULL);
	flann_find_nearest_neighbors_index(kdtreeIndex, testset, count, result, dists, nn, p);
	env->ReleaseFloatArrayElements(searchdata, testset, 0);
	jintArray resArray = env->NewIntArray(count * nn);
	std::cout << "set result count " << count << " nn " << nn << std::endl;
	env->SetIntArrayRegion(resArray, 0, count * nn, (const jint*)result);
	delete[] result;
	delete[] dists;
	return resArray;
}
