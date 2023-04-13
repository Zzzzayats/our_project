#include "main_controller.h"
#include<QQueue>


main_controller::main_controller()
{

}

void main_controller::startCircuit()
{
    QQueue<Block*> queue;
    for (int i = 0; i < Generators.size(); i++)
    {
        queue.enqueue(Generators[i]);
    }

    while (!queue.isEmpty())
    {
        Block* temp_block = queue.dequeue();
        Signal* outSignal = temp_block->work();
        Block* out = temp_block->getOut();
        for (Block* block : out)
        {
            out->setSignal(outSignal);
            if (out->ready())
            {
                queue.enqueue(out);
            }
        }
    }

}
