#include "palettenode.h"

PaletteNode::PaletteNode(const Palette &palette, PaletteNode *next)
    : Palette(palette)
    , m_next(next)
{
}

PaletteNode::~PaletteNode()
{
    delete m_next;
}

PaletteNode::PaletteNode(PaletteNode &&other)
    : Palette(other)
    , m_next(other.m_next)
{
    other.m_next = nullptr;
}

PaletteNode *PaletteNode::next()
{
    return m_next;
}

void PaletteNode::setNext(PaletteNode *next)
{
    m_next = next;
}
