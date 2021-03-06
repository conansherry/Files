/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_immomo_moaservice_impl_nearby_face_bean_KDTree */

#ifndef _Included_com_immomo_moaservice_impl_nearby_face_bean_KDTree
#define _Included_com_immomo_moaservice_impl_nearby_face_bean_KDTree
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_immomo_moaservice_impl_nearby_face_bean_KDTree
 * Method:    NativeInitParams
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_com_immomo_moaservice_impl_nearby_face_bean_KDTree_NativeInitParams
  (JNIEnv *, jobject);

/*
 * Class:     com_immomo_moaservice_impl_nearby_face_bean_KDTree
 * Method:    NativeDestroyParams
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_immomo_moaservice_impl_nearby_face_bean_KDTree_NativeDestroyParams
  (JNIEnv *, jobject, jlong);

/*
 * Class:     com_immomo_moaservice_impl_nearby_face_bean_KDTree
 * Method:    NativeInitBuffer
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_com_immomo_moaservice_impl_nearby_face_bean_KDTree_NativeInitBuffer
  (JNIEnv *, jobject, jlong);

/*
 * Class:     com_immomo_moaservice_impl_nearby_face_bean_KDTree
 * Method:    NativeDestroyBuffer
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_immomo_moaservice_impl_nearby_face_bean_KDTree_NativeDestroyBuffer
  (JNIEnv *, jobject, jlong);

/*
 * Class:     com_immomo_moaservice_impl_nearby_face_bean_KDTree
 * Method:    NativeInsertData
 * Signature: (JJ[F)I
 */
JNIEXPORT jint JNICALL Java_com_immomo_moaservice_impl_nearby_face_bean_KDTree_NativeInsertData
  (JNIEnv *, jobject, jlong, jlong, jfloatArray);

/*
 * Class:     com_immomo_moaservice_impl_nearby_face_bean_KDTree
 * Method:    NativeBuildIndex
 * Signature: (JJJJ)J
 */
JNIEXPORT jlong JNICALL Java_com_immomo_moaservice_impl_nearby_face_bean_KDTree_NativeBuildIndex
  (JNIEnv *, jobject, jlong, jlong, jlong, jlong);

/*
 * Class:     com_immomo_moaservice_impl_nearby_face_bean_KDTree
 * Method:    NativeDestroyIndex
 * Signature: (JJ)I
 */
JNIEXPORT jint JNICALL Java_com_immomo_moaservice_impl_nearby_face_bean_KDTree_NativeDestroyIndex
  (JNIEnv *, jobject, jlong, jlong);

/*
 * Class:     com_immomo_moaservice_impl_nearby_face_bean_KDTree
 * Method:    NativeSearchNearestNeighborsIndex
 * Signature: (JJ[FJI)[I
 */
JNIEXPORT jintArray JNICALL Java_com_immomo_moaservice_impl_nearby_face_bean_KDTree_NativeSearchNearestNeighborsIndex
  (JNIEnv *, jobject, jlong, jlong, jfloatArray, jlong, jint);

#ifdef __cplusplus
}
#endif
#endif
