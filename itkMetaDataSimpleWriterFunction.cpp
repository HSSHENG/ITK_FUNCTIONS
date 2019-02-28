#include "itkMetaDataSimpleWriterFunction.h"

//.................................................................................................
// A SIMPLE FUCTION FOR WRITE 3D IMAGE DATA TO MHD/RAW FILE FOR 3DSLICE VIEWING short type
//.................................................................................................
void itk::MetaDataSimpleWriterFunction(
        std::string metaDataFilePath,
        itk::Image<signed short, 3>::Pointer image)
{
    // typedef
    typedef itk::Image<signed short, 3> ImageType3dS;

    // writer
    itk::MetaImageIOFactory::RegisterOneFactory();
    typedef itk::ImageFileWriter<ImageType3dS> WriterType;
    WriterType::Pointer writer =  WriterType::New();
    writer->SetFileName(metaDataFilePath);
    writer->SetInput(image);
    try
    {
        writer->Write();
    }
    catch(itk::ExceptionObject &ex)
    {
        std::cout<<ex<<std::endl;
        return;
    }

}

//.................................................................................................
// A SIMPLE FUCTION FOR WRITE 3D IMAGE DATA TO MHD/RAW FILE FOR 3DSLICE VIEWING unsigned char type
//.................................................................................................
void itk::MetaDataSimpleWriterFunction(
        std::string metaDataFilePath,
        itk::Image<unsigned char, 3>::Pointer image)
{
    // typedef
    typedef itk::Image<unsigned char, 3> ImageType3dC;

    // writer
    itk::MetaImageIOFactory::RegisterOneFactory();
    typedef itk::ImageFileWriter<ImageType3dC> WriterType;
    WriterType::Pointer writer =  WriterType::New();
    writer->SetFileName(metaDataFilePath);
    writer->SetInput(image);
    try
    {
        writer->Write();
    }
    catch(itk::ExceptionObject &ex)
    {
        std::cout<<ex<<std::endl;
        return;
    }
}

//.................................................................................................
// A SIMPLE FUCTION FOR WRITE 3D IMAGE DATA TO MHD/RAW FILE FOR 3DSLICE VIEWING float type
//.................................................................................................
void itk::MetaDataSimpleWriterFunction(
        std::string metaDataFilePath,
        itk::Image<float, 3>::Pointer image)
{
    // typedef
    typedef itk::Image<float, 3> ImageType3dF;

    // writer
    itk::MetaImageIOFactory::RegisterOneFactory();
    typedef itk::ImageFileWriter<ImageType3dF> WriterType;
    WriterType::Pointer writer =  WriterType::New();
    writer->SetFileName(metaDataFilePath);
    writer->SetInput(image);
    try
    {
        writer->Write();
    }
    catch(itk::ExceptionObject &ex)
    {
        std::cout<<ex<<std::endl;
        return;
    }
}
