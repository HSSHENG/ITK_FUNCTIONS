#include "itkImageTrim2DFunction.h"
#include "itkImageExpand2DFunction.h"
#include "itkQuickView2DFunction.h"
#include <itkImage.h>
#include <itkImageFileReader.h>
#include <itkPNGImageIOFactory.h>

int main()
{
    // typedef
    typedef itk::Image<unsigned char,2> ImageType;

    // tese image path
    std::string path = "..//0.png";
    // reader
    itk::PNGImageIOFactory::RegisterOneFactory();
    typedef itk::ImageFileReader<ImageType> ReaderType;
    ReaderType::Pointer reader = ReaderType::New();
    reader->SetFileName(path);
    reader->Update();
    ImageType::Pointer image = reader->GetOutput();

    itk::QuickView2DFunction(image);
    // trim
    bool trimedOrNot = true;
    itk::ImageTrim2DFunction(image, trimedOrNot);

    itk::QuickView2DFunction(image);

    itk::ImageExpand2DFunction(image, 1);

    itk::QuickView2DFunction(image);
}
