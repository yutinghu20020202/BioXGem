#include <stdio.h>
int hourtommin (int hour, int min){
    return hour * 60 + min;
}

int main(){
    int currentHour, currentMin;
    scanf ("%d:%d", &currentHour, &currentMin);
    int currentTime = hourtommin(currentHour, currentMin);
    int N;
    scanf("%d", &N);
    int num, departureHour, departureMin, duration;
    int FastestTime = 24*60, FastestTrain;
    for (int i=0; i<N; i++){
        scanf("%d %d:%d %d", &num, &departureHour, &departureMin, &duration);
        int departureTime = hourtommin(departureHour, departureMin);
        if (currentTime <= departureTime){
            int arrivalTime = departureTime + duration;
            if (arrivalTime <= FastestTime){
                FastestTime = arrivalTime;
                FastestTrain = num;
            }

        }
    }
    printf("%d/n", FastestTrain);
    return 0;
}