#ifndef CLOCKCLASS
#define CLOCKCLASS

#include <QtGui>

class ClockClass : public QWindow
{
    Q_OBJECT
public:
    ClockClass(QWindow* parent = 0);
    virtual void render(void);

public slots:
    void renderRequest(void);

protected:
    bool event(QEvent *) Q_DECL_OVERRIDE;
    void exposeEvent(QExposeEvent*) Q_DECL_OVERRIDE;
    void resizeEvent(QResizeEvent* event) Q_DECL_OVERRIDE;

private:
    QBackingStore* m_backingStore;
    int m_pendingRequest;
};

#endif // CLOCKCLASS

