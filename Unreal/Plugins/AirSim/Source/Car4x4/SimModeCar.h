#pragma once

#include "CoreMinimal.h"
#include "common/Common.hpp"
#include "SimMode/SimModeWorldBase.h"
#include "VehiclePawnWrapper.h"
#include "SimModeCar.generated.h"


UCLASS()
class AIRSIM_API ASimModeCar : public ASimModeBase
{
    GENERATED_BODY()

public:
    typedef ACar4x4Pawn* VehiclePtr;
    typedef ACar4x4Pawn TVehiclePawn;

    ASimModeCar();
    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

    virtual VehiclePawnWrapper* getFpvVehiclePawnWrapper() override;

    void createVehicles(std::vector<VehiclePtr>& vehicles);

private:
    void setupVehiclesAndCamera(std::vector<VehiclePtr>& vehicles);

private:    
    UClass* external_camera_class_;
    UClass* camera_director_class_;
    UClass* vehicle_pawn_class_;

    TArray<AActor*> spawned_actors_;

    VehiclePawnWrapper* fpv_vehicle_pawn_wrapper_;
};
