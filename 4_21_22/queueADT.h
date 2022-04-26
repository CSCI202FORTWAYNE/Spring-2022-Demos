#ifndef QUEUEADT_H
#define QUEUEADT_H

template <class Type>
class queueADT
{
public:
	virtual bool isEmptyQueue() const = 0;
	virtual bool isFullQueue() const = 0;
	virtual void initializeQueue() = 0;
	virtual Type front() const = 0;
	virtual Type back() const = 0;
	virtual void enqueue(const Type& queueElement) = 0;
	virtual Type dequeue() = 0;
};




#endif