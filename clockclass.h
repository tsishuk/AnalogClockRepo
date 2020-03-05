#ifndef CLOCKCLASS
#define CLOCKCLASS

#include <QtGui>

class ClockClass : public QWindow
{
    Q_OBJECT
public:
    ClockClass(QWindow* parent = 0);
    void render(void);

protected:
    void exposeEvent(QExposeEvent* event) Q_DECL_OVERRIDE;
    void resizeEvent(QResizeEvent* event) Q_DECL_OVERRIDE;

private:
    QBackingStore* m_backingStore;
};

#endif // CLOCKCLASS

