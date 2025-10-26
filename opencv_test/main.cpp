#include <opencv2/opencv.hpp>
#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/objdetect.hpp>
#include <string>
#include <vector>

using namespace std;
using namespace cv;
 vector<vector<int>> mycolors {{156,180,100,255,100,255},{34,104,50,255,87,255}}; 
 vector<string> name={"red","green"};
 vector<Scalar> color={{0,0,255},{0,255,0}};

 void findcolor(Mat img){
 vector<vector<Point>>  contours;
 vector<Vec4i>          hierarchy;     Mat imgHSV,mask,maskcanny;
   cvtColor(img,imgHSV,COLOR_BGR2HSV);
   for(int i=0;i<2;i++)
   {
   Scalar lower(mycolors[i][0],mycolors[i][2],mycolors[i][4]);
   Scalar upper(mycolors[i][1],mycolors[i][3],mycolors[i][5]);    
   inRange(imgHSV,lower,upper,mask);
   Canny(mask,maskcanny,25,75);
   findContours(maskcanny,contours,hierarchy,RETR_EXTERNAL,CHAIN_APPROX_SIMPLE) ;
   vector<vector<Point>> conpoly(contours.size());
 

 for(int j=0;j<contours.size();j++){
   int area =contourArea(contours[j]);
   if(area<2300&&area>1500){
     float peri=arcLength(contours[j],true);
     approxPolyDP(contours[j],conpoly[j],0.02*peri,true);     
     drawContours(img,conpoly,j,Scalar(0,255,255),3);
     putText(img,name[i],Point(50,50),FONT_HERSHEY_DUPLEX,1.75,color[i],1);
    
        }
    }
   }
 }
int main(){
  string path="../TrafficLight.avi";
  VideoCapture cap(path);
  VideoWriter write;
  string outpath="../result1.avi";
  write.open(outpath,VideoWriter::fourcc('M','J','P','G'),30.0,Size(640,200));
  Mat img,reimg;
  while(true){
    cap.read(img);
    if(img.empty()){
      break;
    }
    resize(img,reimg,Size(640,200));
    findcolor(reimg);
    write.write(reimg);
    imshow("img",reimg);
    waitKey(30);
  }
  cap.release();
}























    
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   








