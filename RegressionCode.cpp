#include <cstdlib>
#include <iostream>

class LinearRegressionModel {
    private:
        float* ParameterVector;
        int ParameterSize;

    public:

        LinearRegressionModel(int ParameterSize) {
            ParameterSize = ParameterSize;
            ParameterVector = (float*) malloc ((ParameterSize + 1)* sizeof(float));
            for(int i = 0; i < ParameterSize; i++) {
                if(i == 0) ParameterVector[i] = 1;
                else ParameterVector[i] = 0;
            }
        }

        void ModelOutput(int number_of_input, float Input_Vectors[], float* answer) {

            try{
                if(number_of_input + 1 != ParameterSize) {
                    throw 1;
                }
            } catch (...) {
                std::cout << "Error: 505, Number Of Params not matching.\n";
                answer = NULL;
                return;
            }
            
            *answer = ParameterVector[0];
            for(int i = 0; i < number_of_input; i++) {
                *answer += ParameterVector[i+1]*Input_Vectors[i];
            }
        }


        float CalculateDeviation(int DataSetSize, int number_of_input, float** DataSetInput) {

            try{
                if(number_of_input + 1 != ParameterSize) {
                    throw 1;
                }
            } catch (...) {
                std::cout << "Error: 505, Number Of Params not matching.\n";
                return -1;
            }
            
            float dev = 0;

            for(int i = 0; i < DataSetSize; i++) {
                float temp;
                this->ModelOutput(number_of_input, DataSetInput[i], &temp) ;
                dev += temp;
            }

            return (dev/2);
            
        }

        void TrainLinearRegressionModel(int TestModelSize) {
            
        }
};
