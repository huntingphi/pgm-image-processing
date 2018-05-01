#ifndef FILTER
#define FILTER
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <memory>
#include <sstream>
#include "../include/Image.h"
class Filter
{
    public:
    // friend Image;
    int n;
    std::string input_name;
    std::vector<std::vector<float>> filter_matrix;
    std::vector<std::vector<unsigned char>> data;
    int data_width;
    int data_height;

    Filter(std::string name,Image img):input_name(name){
        n=0;
        // input_name = name;
        std::ifstream file("assets/sample_filters/" + input_name, std::ios::in);
        if (!file.is_open())
        {
            std::cerr << "There was a problem opening the input file" << std::endl;
        }
        file>>n;
        std::cout<<"N: "<<n<<std::endl;
        for (int i = 0;i<n;++i){
            std::vector<float> temp;
            for (int j = 0; j < n; ++j)
            {
                float value;
                file>>value;
                temp.push_back(value);
                // filter_matrix[i][j]= value;
                // std::cout<<" i, j : value "<<i<<", "<<" : "<<value<<std::endl;
            }
                filter_matrix.push_back(temp);
            temp.clear();
        }

        unsigned char *image_data = img.data.get();
        data_height = img.height;
        data_width = img.width;
        for (int i = 0; i < data_height; i++)
        {
            std::vector<unsigned char> temp;
            for (int j = 0; j < data_width; j++)
            {
                temp.push_back(image_data[i + j]);
            }
            data.push_back(temp);
            temp.clear();
        }
    }

    u_char weighted_sum(int r, int c){
        int start_row, end_row, start_col, end_col;
        int delta = n / 2;
        if(r-delta<0){
            start_row = 0;
        }
        else
        {
            start_row = r-delta;
        }

        if (c- delta < 0)
        {
            start_col = 0;
        }
        else
        {
            start_col = c - delta;
        }
        if (r + delta > data_width)
        {
            end_row = data_width;
        }
        else
        {
            end_row = r + delta;
        }

        if (c + delta > data_height)
        {
            end_col = data_height;
        }else{
            end_col = c + delta;
        }

            int m_i = 0;
            int m_j =0;
            // std::cout << "start row end row"<<start_row<<end_row << std::endl;
            // std::cout << "start col end col"<<start_col<<end_col << std::endl;
            u_char w_sum = 0;
            for (int i = start_col; i < end_col; i++)
            {
                for (int j = start_row; j < end_row; j++)
                {
                    // std::cout<<data[i][j]<<std::endl;
                    // std::cout << "VS" << std::endl;


                    w_sum+=data[i][j] * filter_matrix[m_i][m_j];
                    // std::cout << filter_matrix[m_i][m_j] << std::endl;

                    m_j++;
                }
                m_i++;
                m_j = 0;
        }
        // if(data[r][c]==w_sum){
        //     std::cout << "FMLLLLLLLLLLLLLLLLLLLLLLL" << std::endl;
        // }
        return w_sum;
    }

    unsigned char* filter_image()
    {
        unsigned char *resulting_buffer = new unsigned char[data_width*data_height];
                // std::cout << "start row end row" << std::endl;

        for (int i = 0; i < data_height; i++)
        {
            for (int j = 0; j < data_width; j++)
            {

                resulting_buffer[i + j] = weighted_sum(i, j); //data[i][j];
            }
        }
        // Image image(data_width, data_height, resulting_buffer);
        return resulting_buffer;
    }

    // int weighted_sum(int r, int c){
    //     int delta = n/2;
    //     int overflow_r = 0;
    //     int overflow_c = 0;
    //     int offset_r_end = r+delta;
    //     int offset_c_end = c + delta;
    //     int offset_r_beg = r - delta;
    //     int offset_c_beg = c - delta;
    //     if(offset_r_end>data_width){
    //         overflow_r=(offset_r_end-data_width);
    //         offset_r_end+=overflow_r;
    //     }
    //     if(offset_r_beg<0){
    //         overflow_r=(abs(offset_r_beg));
    //         offset_r_end = std::max(offset_r_end,overflow_r);
    //     }
    //     if(offset_c_end>data_height){
    //         overflow_c=(offset_c_end-data_height);
    //         offset_c_end+=overflow_c;
    //     }
    //     if(offset_c_beg<0){
    //         overflow_c+=(abs(offset_c_beg));
    //     }

    // }
    };

#endif