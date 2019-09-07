#pragma once

class Triangle {
    private:
        double base, height;
        static int counter;
    public:
        Triangle(double height, double base);

        void setBase(double b);
        void setHeight(double h);
        double getBase();
        double getHeight();

        static int getCounter() { return counter; };
};