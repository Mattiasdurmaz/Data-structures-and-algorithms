#include "student1drawgraph.h"


const char* nameOfStudent1(){
    return  "Mattias Odo";
}


void studentsDrawGraph(QPainter& painter,  const std::vector<Node>& graph){

    for (const Node& node : graph){
        painter.fillRect(node._point.x(), node._point.y(),1,1, Qt::black);
        for (const Arc& arc : node._outputs){
            if (arc.m_isVisible == true)
                painter.drawLine(node._point, graph[arc.m_ixDestination]._point);
        }
    }
   //TODO
}



