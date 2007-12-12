/********************************************************************
 *           YaST2-GTK - http://en.opensuse.org/YaST2-GTK           *
 ********************************************************************/

#ifndef YGUI_H
#define YGUI_H

#include <gtk/gtk.h>
#include <YSimpleEventHandler.h>

#define ICON_DIR   THEMEDIR "/icons/22x22/apps/"

/* Comment the following line to disable debug messages */
// #define IMPL_DEBUG
#define LOC       fprintf (stderr, "%s (%s)\n", G_STRLOC, G_STRFUNC)
#ifdef IMPL_DEBUG
	#define IMPL      { LOC; }
#else
	#define IMPL      { }
#endif
#define IMPL_RET(a) { IMPL; return (a); }

/* Compatibility */
/*
#if YAST2_VERSION > 2014004
#  define YAST2_YGUI_CHECKBOX_FRAME 1
#elif YAST2_VERSION >= 2014000
#  define YAST2_YGUI_CHECKBOX_FRAME 0
#elif YAST2_VERSION > 2013032
#  define YAST2_YGUI_CHECKBOX_FRAME 1
#else
#  define YAST2_YGUI_CHECKBOX_FRAME 0
#endif
*/

class YGDialog;

#include <YUI.h>

class YGUI: public YUI
{
public:
    YGUI (int argc, char **argv,
          bool with_threads, const char *macro_file);
    virtual ~YGUI();

    static YGUI *ui() { return (YGUI *) YUI::ui(); }

protected:
	virtual YWidgetFactory *createWidgetFactory();
	virtual YOptionalWidgetFactory *createOptionalWidgetFactory();
	virtual YApplication *createApplication();

public:
    YEvent *waitInput (unsigned long timeout_ms, bool block);
	virtual void idleLoop (int fd_ycp);
	virtual YEvent *userInput (unsigned long timeout_millisec);
	virtual YEvent *pollInput();

	virtual void internalError (const char *msg);

	virtual int deviceUnits (YUIDimension dim, float layout_units);
	virtual float layoutUnits (YUIDimension dim, int device_units);
	virtual YCPString glyph (const YCPSymbol &glyphSymbol);

	virtual int	 getDisplayWidth();
	virtual int	 getDisplayHeight();
	virtual int	 getDisplayDepth();
	virtual long getDisplayColors();
	virtual int	 getDefaultWidth();
	virtual int	 getDefaultHeight();
	virtual bool textMode()              IMPL_RET (false)
	virtual bool hasImageSupport()       IMPL_RET (true)
	virtual bool hasLocalImageSupport()  IMPL_RET (true)
	virtual bool hasAnimationSupport()   IMPL_RET (true)
	virtual bool hasIconSupport()        IMPL_RET (true)
	virtual bool hasFullUtf8Support()    IMPL_RET (true)
	virtual bool richTextSupportsTable() IMPL_RET (false)

	virtual void showDialog (YDialog *dialog);
	virtual void closeDialog (YDialog *dialog);

	virtual void busyCursor();
	virtual void normalCursor();

	virtual void makeScreenShot (string filename);
	virtual void beep();
	virtual YCPValue runPkgSelection (YWidget *packageSelector);

	virtual YCPValue askForExistingDirectory (const YCPString &startDir,
		const YCPString &headline);
	virtual YCPValue askForExistingFile (const YCPString &startWith,
		const YCPString &filter, const YCPString &headline);
	virtual YCPValue askForSaveFileName (const YCPString &startWith,
		const YCPString & filter, const YCPString &headline);

    void toggleRecordMacro();

    // Plays a macro, opening a dialog first to ask for the filename
    // activated by Ctrl-Shift-Alt-P
    void askPlayMacro();

	// On Shift-F8, run save_logs
	void askSaveLogs();

    YSimpleEventHandler m_event_handler;
    void    sendEvent (YEvent *event);
    YEvent *pendingEvent() const { return m_event_handler.pendingEvent(); }
    bool    eventPendingFor (YWidget *widget) const
    { return m_event_handler.eventPendingFor (widget); }

private:
    guint busy_timeout;  // for busy cursor
    static gboolean busy_timeout_cb (gpointer data);

    // window-related arguments
    bool m_have_wm, m_no_border, m_fullscreen;
    GtkRequisition m_default_size;

    // for delayed gtk+ init in the right thread
    bool   m_done_init;
    int    m_argc;
    char **m_argv;
    void  checkInit();

    // for screenshots:
    map <string, int> screenShotNb;
    string screenShotNameTemplate;

public:
    // Helpers for internal use [ visibility hidden ]
    int _getDefaultWidth(); int _getDefaultHeight();
    bool setFullscreen() const { return m_fullscreen; }
    bool hasWM() const         { return m_have_wm; }
    bool unsetBorder() const   { return m_no_border; }
};

// debug helpers.
void dumpYastTree (YWidget *widget);
void dumpYastHtml (YWidget *widget);

#include <YWidgetFactory.h>

class YGWidgetFactory : public YWidgetFactory
{
	virtual YDialog *createDialog (YDialogType dialogType, YDialogColorMode colorMode);

    virtual YPushButton *createPushButton (YWidget *parent, const string &label);
	virtual YLabel *createLabel (YWidget *parent, const string &text, bool isHeading, bool isOutputField);
	virtual YInputField *createInputField (YWidget *parent, const string &label, bool passwordMode);
	virtual YCheckBox *createCheckBox (YWidget *parent, const string &label, bool isChecked);
	virtual YRadioButton *createRadioButton (YWidget *parent, const string &label, bool isChecked);
    virtual YComboBox *createComboBox (YWidget * parent, const string & label, bool editable);
	virtual YSelectionBox *createSelectionBox (YWidget *parent, const string &label);
	virtual YTree *createTree (YWidget *parent, const string &label);
	virtual YTable *createTable (YWidget * parent, YTableHeader *header);
	virtual YProgressBar *createProgressBar	(YWidget *parent, const string &label, int maxValue);
	virtual YRichText *createRichText (YWidget *parent, const string &text, bool plainTextMode);

	virtual YIntField *createIntField (YWidget *parent, const string &label, int minVal, int maxVal, int initialVal);
	virtual YMenuButton *createMenuButton (YWidget *parent, const string &label);
	virtual YMultiLineEdit *createMultiLineEdit	(YWidget *parent, const string &label);
	virtual YImage *createImage (YWidget *parent, const string &imageFileName, bool animated);
	virtual YLogView *createLogView (YWidget *parent, const string &label, int visibleLines, int storedLines);
	virtual YMultiSelectionBox *createMultiSelectionBox (YWidget *parent, const string &label);

	virtual YPackageSelector *createPackageSelector (YWidget * parent, long ModeFlags);
	virtual YWidget *createPkgSpecial (YWidget * parent, const string & subwidgetName)
		IMPL_RET (NULL)  // for ncurses

	virtual YLayoutBox *createLayoutBox (YWidget *parent, YUIDimension dimension);

	virtual YSpacing *createSpacing (YWidget *parent, YUIDimension dim, bool stretchable, YLayoutSize_t size);
	virtual YEmpty *createEmpty (YWidget *parent);
	virtual YAlignment *createAlignment (YWidget *parent, YAlignmentType horAlignment, YAlignmentType vertAlignment);
	virtual YSquash *createSquash (YWidget *parent, bool horSquash, bool vertSquash);

	virtual YFrame *createFrame (YWidget *parent, const string &label);
	virtual YCheckBoxFrame *createCheckBoxFrame	(YWidget *parent, const string &label, bool checked);

	virtual YRadioButtonGroup *createRadioButtonGroup (YWidget *parent);
	virtual YReplacePoint *createReplacePoint (YWidget *parent);
};

#include <YOptionalWidgetFactory.h>

class YGOptionalWidgetFactory : public YOptionalWidgetFactory
{
public:
	virtual bool hasWizard() IMPL_RET (true)
	virtual YWizard *createWizard (YWidget *parent, const string &backButtonLabel,
		const string &abortButtonLabel, const string &nextButtonLabel,
		YWizardMode wizardMode);

	virtual bool hasDumbTab() IMPL_RET (true)
	virtual YDumbTab *createDumbTab (YWidget *parent);

	virtual bool hasSlider() IMPL_RET (true)
	virtual YSlider *createSlider (YWidget *parent, const string &label, int minVal,
		int maxVal, int initialVal);

	virtual bool hasDateField() IMPL_RET (true)
	virtual YDateField *createDateField (YWidget *parent, const string &label);

	virtual bool hasTimeField() IMPL_RET (true)
	virtual YTimeField *createTimeField (YWidget *parent, const string &label);

	virtual bool hasBarGraph() IMPL_RET (true)
	virtual YBarGraph *createBarGraph (YWidget *parent);

	virtual bool hasMultiProgressMeter() IMPL_RET (true)
	virtual YMultiProgressMeter *createMultiProgressMeter (YWidget *parent,
		YUIDimension dim, const vector<float> &maxValues);

	virtual bool hasPartitionSplitter() IMPL_RET (true)
	virtual YPartitionSplitter *createPartitionSplitter (YWidget *parent,
		int usedSize, int totalFreeSize, int newPartSize, int minNewPartSize,
		int minFreeSize, const string &usedLabel, const string &freeLabel,
		const string &newPartLabel, const string &freeFieldLabel,
		const string &newPartFieldLabel);

	virtual bool hasDownloadProgress() IMPL_RET (true)
	virtual YDownloadProgress *createDownloadProgress (YWidget *parent,
		const string &label, const string & filename, YFileSize_t expectedFileSize);

	virtual bool hasSimplePatchSelector() IMPL_RET (false)
	virtual YWidget *createSimplePatchSelector (YWidget *parent, long modeFlags)
		IMPL_RET (NULL)
	virtual bool hasPatternSelector() IMPL_RET (false)
	virtual YWidget *createPatternSelector (YWidget *parent, long modeFlags)
		IMPL_RET (NULL)
};

#include <YApplication.h>

class YGApplication : public YApplication
{
public:
	YGApplication();
};

#endif /*YGUI_H*/
