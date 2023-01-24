// Copyright [2023] <Volodymyr Dorozhovets>"

#include <QApplication>

#include "painter_of_rounded_border_of_widget.hpp"
#include "layout_of_external_rounded_border_of_widget.hpp"
#include "layout_of_internal_rounded_border_of_widget.hpp"
#include "layout_of_external_and_internal_rounded_border_of_widget.hpp"
#include "painter_of_save_and_restore.hpp"


namespace N_PainterOfRoundedBorderOfWidget
{
using N_AbstractLayoutOfRoundedBorderOfWidget::LayoutOfExternalRoundedBorderOfWidget;
using N_AbstractLayoutOfRoundedBorderOfWidget::LayoutOfInternalRoundedBorderOfWidget;
using N_AbstractLayoutOfRoundedBorderOfWidget::LayoutOfExternalAndInternalRoundedBorderOfWidget;


void PainterOfRoundedBorderOfWidget::Draw(const QRectF& geometry_of_window)
{
	PainterOfSaveAndRestore painter = PainterOfSaveAndRestore(*this);

	this->Customize();
	this->m_layout->Customize(geometry_of_window);
	this->DrawAccordingToLayout();
}

inline void PainterOfRoundedBorderOfWidget::Customize()
{
	this->setRenderHint(QPainter::Antialiasing);
	this->setPen(Qt::transparent);
}

inline void PainterOfRoundedBorderOfWidget::DrawAccordingToLayout()
{
	this->ReleaseSetColor();
	this->drawPath(*(this->m_layout));
}

inline void PainterOfRoundedBorderOfWidget::ReleaseSetColor()
{
	this->setBrush(this->GetColor());
}

void PainterOfRoundedBorderOfWidget::AllocateMemoryForLayout()
{
	switch (this->m_layout_type)
	{
	case TypeLayoutOfRoundedBorderOfWidget::EXTERNAL:
		this->m_layout = std::make_unique<LayoutOfExternalRoundedBorderOfWidget>();
		break;
	case TypeLayoutOfRoundedBorderOfWidget::INTERNAL:
		this->m_layout = std::make_unique<LayoutOfInternalRoundedBorderOfWidget>();
		break;
	case TypeLayoutOfRoundedBorderOfWidget::EXTERNAL_AND_INTERNAL:
		this->m_layout = std::make_unique<LayoutOfExternalAndInternalRoundedBorderOfWidget>();
		break;
	default:  // NOLINT(clion-misra-cpp2008-6-4-5)
		qDebug() << "A different layout type is selected!";
		QApplication::exit(EXIT_FAILURE);
		break;
	}
}
}  // namespace N_PainterOfRoundedBorderOfWidget
