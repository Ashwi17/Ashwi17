import java.io.*;
 class car
{
    String model;
    String color;
    int year;
    void carinfo(String m,String c,int y){
        model=m;
        color=c;
        year=y;
    }
    String getModel()
    {
        return model;
    }
    String getColor(){
        return color;
    }
    int getYear(){
        return year;
    }
}
class Democar{
        public static void main(String[] args){
            car car1=new car();
            car car2=new car();
            car1.carinfo("Toyoto","Red",2020);
            car2.carinfo("Tata","White",2024);
            System.out.println(car1.getModel());
            System.out.println(car2.getYear());
        }
    }
