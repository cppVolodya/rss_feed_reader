#include <qdebug.h>

#include "painter_of_rounded_border_of_widget.h"
#include "layout_of_external_rounded_border_of_widget.h"
#include "layout_of_internal_rounded_border_of_widget.h"
#include "layout_of_external_and_internal_rounded_border_of_widget.h"


PainterOfRoundedBorderOfWidget::PainterOfRoundedBorderOfWidget(const PainterOfRoundedBorderOfWidget &painter)
	: m_layout_type(painter.m_layout_type),
	  m_layout(nullptr)
{
	this->AllocateMemoryForLayout();

	if(this->m_layout)
	{
		*(this->m_layout) = *painter.m_layout;
	}
}

PainterOfRoundedBorderOfWidget::PainterOfRoundedBorderOfWidget(PainterOfRoundedBorderOfWidget &&painter) noexcept
	: m_layout	   (painter.m_layout	 ),
	  m_layout_type(painter.m_layout_type)
{
	painter.m_layout   	  = nullptr;
	painter.m_layout_type = TypeLayoutOfRoundedBorderOfWidget::NOT_DEFINED;
}

PainterOfRoundedBorderOfWidget& PainterOfRoundedBorderOfWidget::operator=(const PainterOfRoundedBorderOfWidget &painter)
{
	if (this == &painter)
	{
		return *this;
	}

	PainterOfRoundedBorderOfWidget temporary(painter);

	Swap(*this, temporary);

	return *this;
}

PainterOfRoundedBorderOfWidget& PainterOfRoundedBorderOfWidget::operator=(PainterOfRoundedBorderOfWidget &&painter) noexcept
{
	if (this == &painter)
	{
		return *this;
	}

	PainterOfRoundedBorderOfWidget temporary(std::move(painter));

	Swap(*this, temporary);

	return *this;
}

void PainterOfRoundedBorderOfWidget::Draw(const QRectF &geometry_of_window)
{
	this->Customize();
	this->m_layout->Customize(geometry_of_window);
	this->DrawAccordingToLayout();
}

void PainterOfRoundedBorderOfWidget::SetTypeOfLayout(const TypeLayoutOfRoundedBorderOfWidget type_layout) noexcept
{
	this->DeallocateMemoryOfLayoutAndResetLayoutType();

	this->m_layout_type = type_layout;

	this->AllocateMemoryForLayout();
}

inline void Swap(PainterOfRoundedBorderOfWidget &first_object, PainterOfRoundedBorderOfWidget &second_object) noexcept
{
	std::swap(first_object.m_layout_type, second_object.m_layout_type);
	std::swap(first_object.m_layout, 	  second_object.m_layout);
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
		this->m_layout = new LayoutOfExternalRoundedBorderOfWidget;
		break;
	case TypeLayoutOfRoundedBorderOfWidget::INTERNAL:
		this->m_layout = new LayoutOfInternalRoundedBorderOfWidget;
		break;
	case TypeLayoutOfRoundedBorderOfWidget::EXTERNAL_AND_INTERNAL:
		this->m_layout = new LayoutOfExternalAndInternalRoundedBorderOfWidget;
		break;
	case TypeLayoutOfRoundedBorderOfWidget::NOT_DEFINED:
		this->m_layout = nullptr;
		break;
	default:
		this->m_layout = nullptr;
		qDebug() << "A different layout type is selected!";
	}
}

void PainterOfRoundedBorderOfWidget::DeallocateMemoryOfLayoutAndResetLayoutType() noexcept
{
	this->m_layout_type = TypeLayoutOfRoundedBorderOfWidget::NOT_DEFINED;

	delete this->m_layout;
	this->m_layout = nullptr;
}
