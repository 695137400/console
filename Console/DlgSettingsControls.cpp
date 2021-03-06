#include "stdafx.h"
#include "resource.h"

#include "DlgSettingsControls.h"

//////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////

DlgSettingsControls::DlgSettingsControls(CComPtr<IXMLDOMElement>& pOptionsRoot)
: DlgSettingsBase(pOptionsRoot)
{
	IDD = IDD_SETTINGS_CONTROLS;
}

//////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////

LRESULT DlgSettingsControls::OnInitDialog(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
{
	m_controlsSettings.Load(m_pOptionsRoot);

	m_tabCtrl.Attach(GetDlgItem(IDC_TABS_CONTROLS));

	m_tabCtrl.InsertItem(0, Helpers::LoadStringW(IDS_SETTINGS_WINDOWED).c_str());
	m_tabCtrl.InsertItem(1, Helpers::LoadStringW(IDS_SETTINGS_FULLSCREEN).c_str());

	EnableTabControls();

	DoDataExchange(DDX_LOAD);
	return TRUE;
}

//////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////

LRESULT DlgSettingsControls::OnCloseCmd(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	if (wID == IDOK)
	{
		DoDataExchange(DDX_SAVE);

		ControlsSettings& controlsSettings = g_settingsHandler->GetAppearanceSettings().controlsSettings;

		controlsSettings = m_controlsSettings;

		m_controlsSettings.Save(m_pOptionsRoot);
	}

	return 0;
}

//////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////

LRESULT DlgSettingsControls::OnClickedShowTabs(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	DoDataExchange(DDX_SAVE);
	EnableTabControls();
	return 0;
}

//////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////

void DlgSettingsControls::EnableTabControls()
{
	GetDlgItem(IDC_CHECK_HIDE_SINGLE_TAB).EnableWindow(m_controlsSettings.ShowTabs());
	GetDlgItem(IDC_CHECK_TABS_ON_BOTTOM).EnableWindow(m_controlsSettings.ShowTabs());
	GetDlgItem(IDC_CHECK_HIDE_TAB_ICONS).EnableWindow(m_controlsSettings.ShowTabs());
	GetDlgItem(IDC_CHECK_HIDE_TAB_CLOSE_BUTTON).EnableWindow(m_controlsSettings.ShowTabs());
	GetDlgItem(IDC_CHECK_HIDE_TAB_NEW_BUTTON).EnableWindow(m_controlsSettings.ShowTabs());
}

//////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////

LRESULT DlgSettingsControls::OnTabItemChanged(int /*idCtrl*/, LPNMHDR /*pnmh*/, BOOL& /*bHandled*/)
{
	// save FULLSCREEN or WINDOWED settings
	DoDataExchange(DDX_SAVE);

	// switch FULLSCREEN <-> WINDOWED
	m_controlsSettings.bIsFullScreen = m_tabCtrl.GetCurSel() == 1;

	DoDataExchange(DDX_LOAD);
	EnableTabControls();

	return 0;
}

//////////////////////////////////////////////////////////////////////////////
