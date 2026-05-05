#pragma once
#include <math.h>
#include <algorithm>

struct Box
{
    float m_pos_x = 0.0f;
    float m_pos_y = 0.0f;
    float m_width = 1.0f;
    float m_height = 1.0f;
    bool iscol;
    bool iscolb;

    Box() {}


    Box(float x, float y, float w, float h)
        : m_pos_x(x), m_pos_y(y), m_width(w), m_height(h) {}
};



