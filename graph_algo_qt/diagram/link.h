#ifndef LINK_H
#define LINK_H

#include <QGraphicsLineItem>

class Node;

class Link : public QGraphicsLineItem
{
public:
    Link(Node *fromNode, Node *toNode);
    ~Link();

    Node *fromNode() const;
    Node *toNode() const;

    void setColor(const QColor &color, qreal width = 1.0);
    QColor color() const;

    void trackNodes();

    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    Node *myFromNode;
    Node *myToNode;
};

#endif
