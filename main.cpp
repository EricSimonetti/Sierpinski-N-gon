#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <cstdlib>

using namespace std;
void setRandomPoint( double & xr, double & yr );
//gROOT->Reset();

static const int sides = 5;
static const int between = 1;
static const int numPoints = sides+(between*sides);

int main() {
    const double PI = acos(-1.0);
    double deg = (2.0*PI)/numPoints;
    double sideDeg = (2.0*PI)/sides;

    double sum = 1;
    int iterations = floor(numPoints*1.0/4.0);
    for(int k = 1; k<=iterations; k++){
        sum += cos(deg*k);
    }

    double scaler = 1.0/(2.0*sum);
    TH2F *hist2 = new TH2F("2d hist", "h2 polygon", 1000, -1.0, 1.0, 1000, -1.0, 1.0);

    double x[100], y[100];

    for(int i = 0; i<sides; i++){
        x[i*(between+1)] = cos(sideDeg*i);
        y[i*(between+1)] = sin(sideDeg*i);
        hist2 -> Fill(x[i*(between+1)], y[i*(between+1)]);
    }

    cout << endl;

    for(int i = 0; i<numPoints; i+=(between+1)){
        for(int j = 1; j<between+1; j++){
            int index2 = i+(between+1);
            if(i == numPoints-(between+1))
                index2 = 0;
            double deltaY = y[index2] - y[i], deltaX = x[index2] - x[i];

            x[i + j] = x[i] + (deltaX / (between + 1.0)) * j;
            y[i + j] = y[i] + (deltaY / (between + 1.0)) * j;

            hist2->Fill(x[i + j], y[i + j]);
        }
    }

    /*
    cout << endl << endl;
    for(int i = 0; i<numPoints; i++){
        cout << i << "    " << x[i] << "    " << y[i] << endl;
    }
    //*/
    //double plotxScaler = scaler;
    //double plotyScaler = scaler;
    double plotxScaler = 1.0/2.0; //<--- to see polygon
    double plotyScaler = 1.0/2.0; //<--- to see polygon
    TH2F *hist1 = new TH2F("2d hist", "h1 x,yPick", 1000, -2.0*plotxScaler, 2.0*plotxScaler, 1000, -2.0*plotyScaler, 2.0*plotyScaler);

    double xr = 0, yr = 0;
    setRandomPoint(xr, yr);

    static const int numRands = 1000000;
    unsigned long int randomPrecision = 32767;   //RAND_MAX;
    long double randomPrecisionD = 32767;        //RAND_MAX*1.0;

    for(int i = 0; i<numRands; i++) {
        unsigned long int randomHelper = rand()%(randomPrecision);
        double randomNumber = randomHelper/randomPrecisionD;
        int point = 0;

        //find which vertex to use
        for(int r = 0; r<numPoints; r++){
            if(randomNumber>(r*1.0/numPoints)&&randomNumber<((r+1)*1.0/numPoints)){
                point = r;
                r = numPoints;
            }
        }

        //find+add dot
        xr = (xr+x[point])*scaler, yr = (yr+y[point])*scaler;
        hist1->Fill(xr, yr);

        //cout << " point: " << point << endl;
    }



    //ROOT graphics
    //
    //window canvas
    ///*
    TCanvas *c1 = new TCanvas("c1", "Derivative Calculations", 200, 10, 700, 500);
    c1 -> SetFillColor(10);
    c1 -> GetFrame() -> SetFillColor(3);
    c1 -> GetFrame() -> SetBorderSize(2);
    gStyle->SetOptStat(0);

    TPad *pad1_1 = new TPad("p1", "X", .21888726207, 0, .781127379, 1, kWhite, 10, 1);

    pad1_1 -> Draw();

    //position pad
    pad1_1 -> cd();
    pad1_1 -> SetGrid();
    pad1_1 -> GetFrame() -> SetFillColor(10);
    pad1_1 -> GetFrame() -> SetBorderSize(12);

    hist1 -> SetTitle("X");
    hist1 -> SetXTitle("dist");
    hist1 -> SetYTitle("num");
    hist1 -> SetStats(1);
    hist1 -> Draw();

    hist2 ->SetMarkerStyle(20);
    hist2 ->SetMarkerColor(3);
    // hist2 -> SetMarkerSize(.5);
    hist2 -> Draw("same");

    c1 -> cd();
    c1 -> Update();
    //*/
}

void setRandomPoint( double & xr, double & yr ){
    xr = 0;
    yr = 0;
}