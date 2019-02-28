#include "itkImageDataRegularization3DFunction.h"

//.................................................................................................
// REGULARIZATION FOR THESE 3D IMAGE WITH NON-IDENTITY DIRECTION UNSIGNED CHAR FORMAT
//.................................................................................................
void itk::ImageDataRegularization3DFunction(
        itk::Image<unsigned char,3>::Pointer &image)
{
    // typedef
    typedef itk::Image<unsigned char,3> ImageType3dC;

    // region start size spacing direction of 3d image
    ImageType3dC::RegionType region3d = image->GetLargestPossibleRegion();
    ImageType3dC::IndexType start3d = region3d.GetIndex();
    ImageType3dC::SizeType size3d = region3d.GetSize();
    ImageType3dC::SpacingType spacing3d = image->GetSpacing();
    ImageType3dC::DirectionType direction3d = image->GetDirection();
    float r00 = direction3d.GetVnlMatrix()[0][0];
    float r11 = direction3d.GetVnlMatrix()[1][1];
    float r22 = direction3d.GetVnlMatrix()[2][2];

    // check the direction is identity or not if not
    if (abs(r00-1)>1e-6 || abs(r11-1)>1e-6 || abs(r22-1)>1e-6)
    {
        // direction martix
        float r01 = direction3d.GetVnlMatrix()[0][1];
        float r02 = direction3d.GetVnlMatrix()[0][2];
        float r10 = direction3d.GetVnlMatrix()[1][0];
        float r12 = direction3d.GetVnlMatrix()[1][2];
        float r20 = direction3d.GetVnlMatrix()[2][0];
        float r21 = direction3d.GetVnlMatrix()[2][1];

        // start(Index) with 0 is good
        ImageType3dC::PointType origin = image->GetOrigin();
        ImageType3dC::IndexType startIndex;
        startIndex.Fill(0);

        double corner[3];
        double minX = 1E10;
        double maxX = -1E10;
        double minY = 1E10;
        double maxY = -1E10;
        double minZ = 1E10;
        double maxZ = -1E10;

        int indexI[2]{0, int(size3d[0]-1)};
        int indexJ[2]{0, int(size3d[1]-1)};
        int indexK[2]{0, int(size3d[2]-1)};

        for(int I=0;I<2;++I)
        {
            for(int J=0;J<2;++J)
            {
                for(int K=0;K<2;++K)
                {
                    corner[0] =  origin[0] + spacing3d[0]*(indexI[I]+start3d[0])*r00 +
                                             spacing3d[1]*(indexJ[J]+start3d[1])*r01 +
                                             spacing3d[2]*(indexK[K]+start3d[2])*r02;
                    corner[1] =  origin[1] + spacing3d[0]*(indexI[I]+start3d[0])*r10 +
                                             spacing3d[1]*(indexJ[J]+start3d[1])*r11 +
                                             spacing3d[2]*(indexK[K]+start3d[2])*r12;
                    corner[2] =  origin[2] + spacing3d[0]*(indexI[I]+start3d[0])*r20 +
                                             spacing3d[1]*(indexJ[J]+start3d[1])*r21 +
                                             spacing3d[2]*(indexK[K]+start3d[2])*r22;
                    minX = minX<corner[0]?minX:corner[0];
                    maxX = maxX>corner[0]?maxX:corner[0];
                    minY = minY<corner[1]?minY:corner[1];
                    maxY = maxY>corner[1]?maxY:corner[1];
                    minZ = minZ<corner[2]?minZ:corner[2];
                    maxZ = maxZ>corner[2]?maxZ:corner[2];

                }
            }
        }


        // new origion
        ImageType3dC::PointType originResample;
        originResample[0] = minX;
        originResample[1] = minY;
        originResample[2] = minZ;

        //new size
        ImageType3dC::SizeType sizeResample;
        sizeResample[0] = round((maxX-minX)/spacing3d[0])+1;
        sizeResample[1] = round((maxY-minY)/spacing3d[1])+1;
        sizeResample[2] = round((maxZ-minZ)/spacing3d[2])+1;


        ImageType3dC::DirectionType desiredDirection;
        desiredDirection.SetIdentity();
        typedef itk::ResampleImageFilter<ImageType3dC, ImageType3dC> ResampleImageFilterType;
        ResampleImageFilterType::Pointer resampleFilter = ResampleImageFilterType::New();
        typedef itk::NearestNeighborInterpolateImageFunction<ImageType3dC, double> InterpolatorType;
        InterpolatorType::Pointer interpolator = InterpolatorType::New();
        resampleFilter->SetInterpolator( interpolator );
        resampleFilter->SetOutputDirection(desiredDirection);
        resampleFilter->SetDefaultPixelValue(0);
        resampleFilter->SetSize(sizeResample);
        resampleFilter->SetOutputOrigin(originResample);
        resampleFilter->SetOutputSpacing(spacing3d);
        resampleFilter->SetOutputStartIndex(startIndex);
        resampleFilter->SetInput(image);
        try
        {
            resampleFilter->Update();
        }
        catch( itk::ExceptionObject & error )
        {
            std::cout<< "Error Update in CTCoachSegmentation3DFunction"<<std::endl;
            std::cout << "Error: " << error << std::endl;
            return;
        }

        // give back
        image = resampleFilter->GetOutput();
    }

}

//.................................................................................................
// REGULARIZATION FOR THESE 3D IMAGE WITH NON-IDENTITY DIRECTION SHORT FORMAT
//.................................................................................................
void itk::ImageDataRegularization3DFunction(
        itk::Image<short,3>::Pointer &image)
{
    // typedef
    typedef itk::Image<short,        3> ImageType3dS;

    // region start size spacing direction of 3d image
    ImageType3dS::RegionType region3d = image->GetLargestPossibleRegion();
    ImageType3dS::IndexType start3d = region3d.GetIndex();
    ImageType3dS::SizeType size3d = region3d.GetSize();
    ImageType3dS::SpacingType spacing3d = image->GetSpacing();
    ImageType3dS::DirectionType direction3d = image->GetDirection();
    float r00 = direction3d.GetVnlMatrix()[0][0];
    float r11 = direction3d.GetVnlMatrix()[1][1];
    float r22 = direction3d.GetVnlMatrix()[2][2];

    // check the direction is identity or not if not
    if (abs(r00-1)>1e-6 || abs(r11-1)>1e-6 || abs(r22-1)>1e-6)
    {
        // direction martix
        float r01 = direction3d.GetVnlMatrix()[0][1];
        float r02 = direction3d.GetVnlMatrix()[0][2];
        float r10 = direction3d.GetVnlMatrix()[1][0];
        float r12 = direction3d.GetVnlMatrix()[1][2];
        float r20 = direction3d.GetVnlMatrix()[2][0];
        float r21 = direction3d.GetVnlMatrix()[2][1];

        // start(Index) with 0 is good
        ImageType3dS::PointType origin = image->GetOrigin();
        ImageType3dS::IndexType startIndex;
        startIndex.Fill(0);

        double corner[3];
        double minX = 1E10;
        double maxX = -1E10;
        double minY = 1E10;
        double maxY = -1E10;
        double minZ = 1E10;
        double maxZ = -1E10;

        int indexI[2]{0, int(size3d[0]-1)};
        int indexJ[2]{0, int(size3d[1]-1)};
        int indexK[2]{0, int(size3d[2]-1)};

        for(int I=0;I<2;++I)
        {
            for(int J=0;J<2;++J)
            {
                for(int K=0;K<2;++K)
                {
                    corner[0] =  origin[0] + spacing3d[0]*(indexI[I]+start3d[0])*r00 +
                                             spacing3d[1]*(indexJ[J]+start3d[1])*r01 +
                                             spacing3d[2]*(indexK[K]+start3d[2])*r02;
                    corner[1] =  origin[1] + spacing3d[0]*(indexI[I]+start3d[0])*r10 +
                                             spacing3d[1]*(indexJ[J]+start3d[1])*r11 +
                                             spacing3d[2]*(indexK[K]+start3d[2])*r12;
                    corner[2] =  origin[2] + spacing3d[0]*(indexI[I]+start3d[0])*r20 +
                                             spacing3d[1]*(indexJ[J]+start3d[1])*r21 +
                                             spacing3d[2]*(indexK[K]+start3d[2])*r22;
                    minX = minX<corner[0]?minX:corner[0];
                    maxX = maxX>corner[0]?maxX:corner[0];
                    minY = minY<corner[1]?minY:corner[1];
                    maxY = maxY>corner[1]?maxY:corner[1];
                    minZ = minZ<corner[2]?minZ:corner[2];
                    maxZ = maxZ>corner[2]?maxZ:corner[2];

                }
            }
        }


        // new origion
        ImageType3dS::PointType originResample;
        originResample[0] = minX;
        originResample[1] = minY;
        originResample[2] = minZ;

        //new size
        ImageType3dS::SizeType sizeResample;
        sizeResample[0] = round((maxX-minX)/spacing3d[0])+1;
        sizeResample[1] = round((maxY-minY)/spacing3d[1])+1;
        sizeResample[2] = round((maxZ-minZ)/spacing3d[2])+1;


        ImageType3dS::DirectionType desiredDirection;
        desiredDirection.SetIdentity();
        typedef itk::ResampleImageFilter<ImageType3dS, ImageType3dS> ResampleImageFilterType;
        ResampleImageFilterType::Pointer resampleFilter = ResampleImageFilterType::New();
        typedef itk::NearestNeighborInterpolateImageFunction<ImageType3dS, double> InterpolatorType;
        InterpolatorType::Pointer interpolator = InterpolatorType::New();
        resampleFilter->SetInterpolator( interpolator );
        resampleFilter->SetOutputDirection(desiredDirection);
        resampleFilter->SetDefaultPixelValue(-1024);
        resampleFilter->SetSize(sizeResample);
        resampleFilter->SetOutputOrigin(originResample);
        resampleFilter->SetOutputSpacing(spacing3d);
        resampleFilter->SetOutputStartIndex(startIndex);
        resampleFilter->SetInput(image);
        try
        {
            resampleFilter->Update();
        }
        catch( itk::ExceptionObject & error )
        {
            std::cout<< "Error Update in CTCoachSegmentation3DFunction"<<std::endl;
            std::cout << "Error: " << error << std::endl;
            return;
        }

        // give back
        image = resampleFilter->GetOutput();
    }

}


//.................................................................................................
// REGULARIZATION FOR THESE 3D IMAGE WITH NON-IDENTITY DIRECTION FLOAT FORMAT
//.................................................................................................
void itk::ImageDataRegularization3DFunction(
        itk::Image<float,3>::Pointer &image)
{
    // typedef
    typedef itk::Image<float,        3> ImageType3dF;

    // region start size spacing direction of 3d image
    ImageType3dF::RegionType region3d = image->GetLargestPossibleRegion();
    ImageType3dF::IndexType start3d = region3d.GetIndex();
    ImageType3dF::SizeType size3d = region3d.GetSize();
    ImageType3dF::SpacingType spacing3d = image->GetSpacing();
    ImageType3dF::DirectionType direction3d = image->GetDirection();
    float r00 = direction3d.GetVnlMatrix()[0][0];
    float r11 = direction3d.GetVnlMatrix()[1][1];
    float r22 = direction3d.GetVnlMatrix()[2][2];

    // check the direction is identity or not if not
    if (abs(r00-1)>1e-6 || abs(r11-1)>1e-6 || abs(r22-1)>1e-6)
    {
        // only god and I know what is this part mean!
        // direction martix
        float r01 = direction3d.GetVnlMatrix()[0][1];
        float r02 = direction3d.GetVnlMatrix()[0][2];
        float r10 = direction3d.GetVnlMatrix()[1][0];
        float r12 = direction3d.GetVnlMatrix()[1][2];
        float r20 = direction3d.GetVnlMatrix()[2][0];
        float r21 = direction3d.GetVnlMatrix()[2][1];

        // start(Index) with 0 is good
        ImageType3dF::PointType origin = image->GetOrigin();
        ImageType3dF::IndexType startIndex;
        startIndex.Fill(0);

        double corner[3];
        double minX = 1E10;
        double maxX = -1E10;
        double minY = 1E10;
        double maxY = -1E10;
        double minZ = 1E10;
        double maxZ = -1E10;

        int indexI[2]{0, int(size3d[0]-1)};
        int indexJ[2]{0, int(size3d[1]-1)};
        int indexK[2]{0, int(size3d[2]-1)};

        for(int I=0;I<2;++I)
        {
            for(int J=0;J<2;++J)
            {
                for(int K=0;K<2;++K)
                {
                    corner[0] =  origin[0] + spacing3d[0]*(indexI[I]+start3d[0])*r00 +
                                             spacing3d[1]*(indexJ[J]+start3d[1])*r01 +
                                             spacing3d[2]*(indexK[K]+start3d[2])*r02;
                    corner[1] =  origin[1] + spacing3d[0]*(indexI[I]+start3d[0])*r10 +
                                             spacing3d[1]*(indexJ[J]+start3d[1])*r11 +
                                             spacing3d[2]*(indexK[K]+start3d[2])*r12;
                    corner[2] =  origin[2] + spacing3d[0]*(indexI[I]+start3d[0])*r20 +
                                             spacing3d[1]*(indexJ[J]+start3d[1])*r21 +
                                             spacing3d[2]*(indexK[K]+start3d[2])*r22;
                    minX = minX<corner[0]?minX:corner[0];
                    maxX = maxX>corner[0]?maxX:corner[0];
                    minY = minY<corner[1]?minY:corner[1];
                    maxY = maxY>corner[1]?maxY:corner[1];
                    minZ = minZ<corner[2]?minZ:corner[2];
                    maxZ = maxZ>corner[2]?maxZ:corner[2];

                }
            }
        }


        // new origion
        ImageType3dF::PointType originResample;
        originResample[0] = minX;
        originResample[1] = minY;
        originResample[2] = minZ;

        //new size
        ImageType3dF::SizeType sizeResample;
        sizeResample[0] = round((maxX-minX)/spacing3d[0])+1;
        sizeResample[1] = round((maxY-minY)/spacing3d[1])+1;
        sizeResample[2] = round((maxZ-minZ)/spacing3d[2])+1;


        ImageType3dF::DirectionType desiredDirection;
        desiredDirection.SetIdentity();
        typedef itk::ResampleImageFilter<ImageType3dF, ImageType3dF> ResampleImageFilterType;
        ResampleImageFilterType::Pointer resampleFilter = ResampleImageFilterType::New();
        typedef itk::NearestNeighborInterpolateImageFunction<ImageType3dF, double> InterpolatorType;
        InterpolatorType::Pointer interpolator = InterpolatorType::New();
        resampleFilter->SetInterpolator( interpolator );
        resampleFilter->SetOutputDirection(desiredDirection);
        resampleFilter->SetDefaultPixelValue(-1024);
        resampleFilter->SetSize(sizeResample);
        resampleFilter->SetOutputOrigin(originResample);
        resampleFilter->SetOutputSpacing(spacing3d);
        resampleFilter->SetOutputStartIndex(startIndex);
        resampleFilter->SetInput(image);
        try
        {
            resampleFilter->Update();
        }
        catch( itk::ExceptionObject & error )
        {
            std::cout<< "Error Update in CTCoachSegmentation3DFunction"<<std::endl;
            std::cout << "Error: " << error << std::endl;
            return;
        }

        // give back
        image = resampleFilter->GetOutput();
    }

}
