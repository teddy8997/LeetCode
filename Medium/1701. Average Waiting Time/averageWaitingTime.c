

double averageWaitingTime(int** customers, int customersSize, int* customersColSize){
    int time = 0;
    double wait = 0;
    for(int i = 0; i < customersSize; i++){
        if(customers[i][0] > time){
            time = customers[i][0];
        }
        time += customers[i][1];
        wait += time - customers[i][0];
    }
    return wait / customersSize;
}