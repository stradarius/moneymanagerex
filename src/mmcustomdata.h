/*******************************************************
Copyright (C) 2017 Gabriele-V
Copyright (C) 2018, 2021 Nikolay Akimov

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
********************************************************/

#pragma once
#include "defs.h"
#include "Model_CustomField.h"
#include "Model_Checking.h"


class wxDatePickerCtrl;
class mmTextCtrl;
class wxDialog;

class mmCustomData : public wxDialog
{
public:
    mmCustomData();
    bool FillCustomFields(wxBoxSizer* box_sizer);
    bool SaveCustomValues(int ref_id);
    void UpdateCustomValues(int ref_id);
    bool ValidateCustomValues(int ref_id);
    const wxString GetWidgetData(wxWindowID controlID) const;
    int GetWidgetType(wxWindowID controlID) const;
    size_t GetCustomFieldsCount() const;
    size_t GetActiveCustomFieldsCount() const;
    std::map<wxString, wxString> GetActiveCustomFields() const;
    void SetBaseID(wxWindowID id);
    wxWindowID GetBaseID() const;
    void SetLabelID(wxWindowID id);
    wxWindowID GetLabelID() const;
    void ResetRefID();
    // TODO: void SetRefID(int ref_id) { m_ref_id = ref_id; }
    bool IsSomeWidgetChanged() const;
    bool IsDataFound(const Model_Checking::Full_Data &tran);
    void ResetWidgetsChanged();
    void ClearSettings() const;
    bool IsCustomPanelShown() const;
    void ShowHideCustomPanel() const;

protected:
    mmCustomData(wxDialog* dialog, const wxString& ref_type, int ref_id);
private:
    wxDialog* m_dialog;
    wxStaticBox* m_static_box;
    const wxString m_ref_type;
    int m_ref_id;
    Model_CustomField::Data_Set m_fields;
    std::map<wxWindowID, wxString> m_data_changed;
    void OnStringChanged(wxCommandEvent& event);
    void OnDateChanged(wxDateEvent& event);
    void OnTimeChanged(wxDateEvent& event);
    void OnMultiChoice(wxCommandEvent& event);
    void OnSingleChoice(wxCommandEvent& event);
    void OnCheckBoxChanged(wxCommandEvent& event);
    void OnCheckBoxActivated(wxCommandEvent& event);
    void OnDoubleChanged(wxCommandEvent& event);
    void OnIntegerChanged(wxCommandEvent& event);
    bool IsWidgetChanged(wxWindowID id);
    void SetWidgetChanged(wxWindowID id, const wxString& data);
    void ResetWidgetChanged(wxWindowID id);
    wxWindowID m_init_control_id;
    wxWindowID m_init_label_id;

};

class mmCustomDataTransaction : public mmCustomData
{
public:
    mmCustomDataTransaction(wxDialog* dialog, int ref_id, wxWindowID base_id);
};

inline void       mmCustomData::SetLabelID(wxWindowID id) { m_init_label_id = id; }
inline void       mmCustomData::ResetRefID() { m_ref_id = -1; }
inline void       mmCustomData::SetBaseID(wxWindowID id) { m_init_control_id = id; }
inline size_t     mmCustomData::GetCustomFieldsCount() const { return m_fields.size(); }
inline wxWindowID mmCustomData::GetBaseID() const { return m_init_control_id; }
inline wxWindowID mmCustomData::GetLabelID() const { return m_init_label_id; }

