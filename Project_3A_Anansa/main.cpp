#include <QCoreApplication>
#include "body.h"
#include "odesolver.h"
#include "system.h"

// int main(int argc, char *argv[])
// {
//    QCoreApplication a(argc, argv);

//    return a.exec();
// }

int main() {
   System* sys = new System("two_body.text");
   int a = 2;
   return a;
}
