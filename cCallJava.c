#include <jni.h>  
#include <stdlib.h>  
#include <stdio.h> 
int main(int argc,char* argv[])  
{  
        JavaVMOption options[1];  
        JNIEnv *env;  //c语言编写一个java虚拟机跑hello.class文件
        JavaVM *jvm;  //找classID和调用class方法来自这里
        JavaVMInitArgs vm_args;  
        long status;  
        jclass cls;  
        jmethodID mid;  
        jint square;  
        jobjectArray applicationArgs;

        options[0].optionString = "-Djava.class.path=.";  //path=.表明类路径（如hello.class）在当前路径，可以接收路径参数
        vm_args.version = 0x00010002;  //也可以写成JNI_VERSION_1_2;的宏，指明所用的虚拟机版本
        vm_args.nOptions = 1;  
        vm_args.options = options;  
        status = JNI_CreateJavaVM(&jvm, (void**)&env, &vm_args);  

        if (status != JNI_ERR)  
        {   
                printf("create JVM successfully\n");//创建java虚拟机成功
                cls = (*env)->FindClass(env,"hello");  //在当前路径.中寻找hello.class
                if(cls !=0)  
                {   
                        printf("find class successfully\n");//成功找到hello.class
                        mid = (*env)->GetStaticMethodID(env, cls, "StaticFunction", "()V");//找名为 StaticFunction，接收参数为()返回类型为V(oid)的静态函数ID,这些方法可用javap -s hello来查看出所有可调用方法 以及参数列表
                        if(mid !=0)
                        {    
                                printf("get static method successfully\n");//找到
                                (*env)->CallStaticVoidMethod(env, cls, mid, applicationArgs);// 调用，applicationArgs是该函数如果需要参数，用来传参数
                        }   

                }   
                (*jvm)->DestroyJavaVM(jvm);   //摧毁虚拟机
                return 0;  
        }   
        else  
                return -1;  

}
