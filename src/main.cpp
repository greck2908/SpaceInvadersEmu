/*  main.cpp  - Yann BOUCHER (yann) 24/01/2016
**
**
**            DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
**                    Version 2, December 2004
**
** Copyright (C) 2004 Sam Hocevar <sam@hocevar.net>
**
** Everyone is permitted to copy and distribute verbatim or modified
** copies of this license document, and changing it is allowed as long
** as the name is changed.
**
**            DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
**   TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION
**
**  0. You just DO WHAT THE FUCK YOU WANT TO.
*/

#include <QApplication>
#include <QMessageBox>

#include "mainwindow.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setKeyboardInputInterval(0);
    QCoreApplication::setApplicationName("Space Invaders");

    try
    {
        MainWindow w;
        w.show();

        return a.exec();
    }
    catch (const i8080::emu_error& e)
    {
        QMessageBox::critical(nullptr, "Erreur lors de l'émulation", QString("Erreur fatale de l'émulateur : ") + e.what(),
                              QMessageBox::Close);
    }
    catch (const std::exception& e)
    {
        QMessageBox::critical(nullptr, "Erreur lors de l'émulation", QString("Erreur fatale : ") + e.what(),
                              QMessageBox::Close);
    }
    catch (...)
    {
        QMessageBox::critical(nullptr, "Erreur inconnue !?", "Erreur fatale inconnue ! Peut-être plus d'infos dans stderr ?",
                              QMessageBox::Close);
    }

}
