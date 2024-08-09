import java.io.*;
class student{
    private String name;
    //default constructor
    private int age;
    student(){
        name=null;
        age=0;
    }
    //parameter constructor
    student(String n,int a){
        name=n;
        age=a;
    }
String getName(){
    return name;
}
int getAge(){
    return age;
}
}
class studentdemo
{
 public static void main(String[] args){
     student s1=new student("Ashwini",19);
     student s2=new student("Ashwika",18);
     student s3=new student();
     s3=s1;
     System.out.println(s1.getName()+"  "+ s1.getAge());
     System.out.println(s2.getName()+" "+s2.getAge());
     System.out.println(s3.getName());
 }   
}
