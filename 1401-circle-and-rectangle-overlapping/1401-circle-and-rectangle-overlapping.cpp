class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        //we just have to find the closest point of square or rect from circle and find its distance.
        int xi,yi;
        if(x1>xCenter){
            xi=x1;
        }
        else if(x2<xCenter){
            xi=x2;
        }
        else{
            xi=xCenter;
        }
        if(y1>yCenter){
            yi=y1;
        }
        else if(y2<yCenter){
            yi=y2;
        }
        else{
            yi=yCenter;
        }
        //now find distance of closest pooint from centre of circle 
        int d=(xCenter-xi)*(xCenter-xi)+(yCenter-yi)*(yCenter-yi);
        if(d<=radius*radius){
            return true;
        }
        else{
            return false;
        }
    }
};