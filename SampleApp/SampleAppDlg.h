
// SampleAppDlg.h : �w�b�_�[ �t�@�C��
//

#pragma once
#include "UiLogic.h"
#include "afxwin.h"

// CSampleAppDlg �_�C�A���O
class CSampleAppDlg : public CDialogEx
{
	UiLogic<CListBox, CEdit> m_logic;

// �R���X�g���N�V����
public:
	CSampleAppDlg(CWnd* pParent = NULL);	// �W���R���X�g���N�^�[

// �_�C�A���O �f�[�^
	enum { IDD = IDD_SAMPLEAPP_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �T�|�[�g


// ����
protected:
	HICON m_hIcon;

	// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnAdd();
private:
	CEdit m_edt_item;
	CListBox m_lst_items;
};
