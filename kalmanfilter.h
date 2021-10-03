#ifndef KALMANFILTER_H
#define KALMANFILTER_H

class KalmanFilterSimple1D
{
private:
    double X0;
    double P0;

    double F;
    double Q;
    double H;
    double R;

    double State;
    double Covariance;
public:
    explicit KalmanFilterSimple1D(double q, double r, double f = 1, double h = 1);
    void SetState(double state, double covariance);
    void Correct(double data);
};

#endif // KALMANFILTER_H
