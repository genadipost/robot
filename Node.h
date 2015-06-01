  /*
 * Node.h
 *
 *  Created on: Jun 1, 2015
 *      Author: colman
 */

#ifndef NODE_H_
#define NODE_H_

class Node {

private:

	int xPos;
	int yPos;
	int distance;
	int priority;

public:
	Node();
	virtual ~Node();
	Node(int x,int y, int d,int p);
	int getxPos() const;
	int getyPos() const;
	int getDistance() const;
	int getPriority() const;
	void updatePriority(const int & xDest, const int & yDest);
	void updateDistance();
	const int & estimateDistance(const int & xDest, const int & yDest) const;
};

#endif /* NODE_H_ */
