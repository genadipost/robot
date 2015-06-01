/*
 * Node.cpp
 *
 *  Created on: Jun 1, 2015
 *      Author: colman
 */

#include "Node.h"
#include <stdio.h>
#include <stdlib.h>

Node::Node()
{
	// TODO Auto-generated constructor stub

}

Node::~Node()
{
	// TODO Auto-generated destructor stub
}

/** constructor **/
Node::Node(int x,int y, int d,int p)
{
    xPos=x;
    yPos=y;
    distance=d;
    priority=p;
}

/** getters for variables **/
//current Node xPosition
int Node::getxPos() const
{
    return xPos;
}

//current Node yPosition
int Node::getyPos() const
{
    return yPos;
}

//gscore
int Node::getDistance() const
{
    return distance;
}

//fscore
int Node::getPriority() const
{
    return priority;
}

/** Updates the priority; the lower the fscore the higer the priority
 *  the fscore is the sum of:
 *  -path-cost (gscore) (which is the distance from the starting Node to the current Node)
 *  -heuristic estimate (hscore) (which is an estimate of the distance from the current Node to the destination Node)
 *
**/
void Node::updatePriority(const int & xDest, const int & yDest)
{
    priority = distance + estimateDistance(xDest,yDest)*10;
}

void Node::updateDistance()
{
	//const int & direction
    distance +=10;
}


/** Estimate function for the remaining distance to the goal
*   here it's based on the Manhattan distance;
*   which is the distance between two points in a grid based on a strictly horizontal & veritcal path;
*   => sum of vertical & horizontal components
**/
const int & Node::estimateDistance(const int & xDest, const int & yDest) const
{
    static int xDistance,yDistance,totalDistance;
    xDistance=xDest-xPos;
    yDistance=yDest-yPos;

    totalDistance=abs(xDistance)+abs(yDistance);

    return (totalDistance);
}

/** class functor (I think) to compare elements using:
 *  operator overloading: "<" gets overloaded which we are going to use in our priority queue
*   to determine priority of a Node in our queue;
*   returns true if Node a has a lower fscore compared to Node b
*
*   there is an ambiguity here: < -- >; better to make both >
*   also prototype is now friend which could probably be replaced with this for the first
*   argument; it advantage is that because of the friend function the operand order can be reversed
*   this doesn't really looks to favor our application; so should I use it or not?
**/
bool operator<(const Node & a, const Node & 	b){
    return a.getPriority() > b.getPriority();
}
