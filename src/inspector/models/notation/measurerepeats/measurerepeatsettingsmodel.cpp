#include "measurerepeatsettingsmodel.h"

using namespace mu::inspector;

MeasureRepeatSettingsModel::MeasureRepeatSettingsModel(QObject* parent, IElementRepositoryService* repository)
    : AbstractInspectorModel(parent, repository)
{
    setModelType(InspectorModelType::TYPE_MEASURE_REPEAT);
    setTitle(tr("Measure repeat"));
    createProperties();
}

void MeasureRepeatSettingsModel::createProperties()
{
    m_numberPosition = buildPropertyItem(Ms::Pid::MEASURE_REPEAT_NUMBER_POS);
}

void MeasureRepeatSettingsModel::requestElements()
{
    m_elementList = m_repository->findElementsByType(Ms::ElementType::MEASURE_REPEAT);
}

void MeasureRepeatSettingsModel::loadProperties()
{
    loadPropertyItem(m_numberPosition);
}

void MeasureRepeatSettingsModel::resetProperties()
{
    m_numberPosition->resetToDefault();
}

PropertyItem* MeasureRepeatSettingsModel::numberPosition() const
{
    return m_numberPosition;
}
