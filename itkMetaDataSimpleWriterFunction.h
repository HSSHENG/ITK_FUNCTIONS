#ifndef ITKMETADATASIMPLEWRITERFUNCTION_H
#define ITKMETADATASIMPLEWRITERFUNCTION_H

#include <itkImage.h>
#include <itkMetaImageIOFactory.h>
#include <itkImageFileWriter.h>

namespace itk
{
    //.................................................................................................
    // A SIMPLE FUCTION FOR WRITE 3D IMAGE DATA TO MHD/RAW FILE FOR 3DSLICE VIEWING short type
    //.................................................................................................
    void MetaDataSimpleWriterFunction(
            std::string metaDataFilePath,
            itk::Image<signed short, 3>::Pointer image);

    //.................................................................................................
    // A SIMPLE FUCTION FOR WRITE 3D IMAGE DATA TO MHD/RAW FILE FOR 3DSLICE VIEWING unsigned char type
    //.................................................................................................
    void MetaDataSimpleWriterFunction(
            std::string metaDataFilePath,
            itk::Image<unsigned char, 3>::Pointer image);

    //.................................................................................................
    // A SIMPLE FUCTION FOR WRITE 3D IMAGE DATA TO MHD/RAW FILE FOR 3DSLICE VIEWING float type
    //.................................................................................................
    void MetaDataSimpleWriterFunction(
            std::string metaDataFilePath,
            itk::Image<float, 3>::Pointer image);
}

#endif // ITKMETADATASIMPLEWRITERFUNCTION_H
