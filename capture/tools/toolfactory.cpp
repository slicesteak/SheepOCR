#include "toolfactory.h"

#include "exittool.h"
#include "markertool.h"
#include "copytool.h"
#include "movetool.h"

#include "savetool.h"

#include "sizeindicatortool.h"

#include "applauncher.h"


ToolFactory::ToolFactory(QObject *parent) : QObject(parent)
{

}

CaptureTool* ToolFactory::CreateTool(
        CaptureButton::ButtonType t,
        QObject *parent)
{
    CaptureTool *tool;
    switch (t) {
//    case CaptureButton::TYPE_ARROW:
//        tool = new ArrowTool(parent);
//        break;
//    case CaptureButton::TYPE_CIRCLE:
//        tool = new CircleTool(parent);
//        break;
    case CaptureButton::TYPE_EXIT:
        tool = new ExitTool(parent);
        break;
	case CaptureButton::TYPE_COPY:
		tool = new CopyTool(parent);
		break;
    case CaptureButton::TYPE_MOVESELECTION:
        tool = new MoveTool(parent);
        break;
//    case CaptureButton::TYPE_PENCIL:
//        tool = new PencilTool(parent);
//        break;
    case CaptureButton::TYPE_SAVE:
        tool = new SaveTool(parent);
        break;
//    case CaptureButton::TYPE_SELECTION:
//        tool = new SelectionTool(parent);
//        break;
//    case CaptureButton::TYPE_UNDO:
//        tool = new UndoTool(parent);
//        break;
//    case CaptureButton::TYPE_BLUR:
//        tool = new BlurTool(parent);
//        break;
	default:
		{
			Q_ASSERT(false && "no matchtype");
			tool = nullptr;
			break;
		}
    }
    return tool;
}
