cmake_minimum_required(VERSION 3.16)
project(qosbrowser)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 自动处理 UI 和资源文件
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOMOC ON)

# 查找 Qt 库
find_package(Qt6 REQUIRED COMPONENTS Core Gui Sql Concurrent Widgets)

# 设置包含目录
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/third/cos/include
    ${CMAKE_CURRENT_SOURCE_DIR}/third/cos/third_party/include
)

# 添加源文件
set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/fend/uicom/UiBaseDialog.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/fend/uicom/UiBreadWidget.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/fend/uicom/UiComboLine.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/fend/uicom/UiLineEdit.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/fend/uicom/UiMessageBox.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/fend/uicom/UiPageWidget.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/fend/uicom/UiProgressWidget.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/fend/uicom/UiPushButton.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/fend/uicom/UiQosDialog.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/fend/uicom/UiTableView.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/fend/uidelegates/UiTableItemDelegate.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/fend/uilogin/UiLoginDialog.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/fend/uimain/UiBucketsListWidget.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/fend/uimain/UiBucketsTableWidget.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/fend/uimain/UiCreateBucketDialog.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/fend/uimain/UiObjectsTableWidget.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/fend/uimain/UiToolBarWidget.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/fend/uitransfer/UiDownload.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/fend/uitransfer/UiTransfer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/fend/uitransfer/UiUpload.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/helper/ByteHelper.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/plugins/ManPlugin.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/bend/dao/clouds/DaoCloudsCos.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/bend/dao/clouds/DaoCloudsMock.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/bend/dao/configs/Version.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/bend/dao/configs/VersionCmd.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/bend/dao/configs/VersionJson.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/bend/dao/dbs/DaoLoginInfo.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/bend/dao/dbs/DaoLoginInfoSqlite.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/bend/dao/logs/BasicLogger.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/bend/dao/logs/LoggerQDebug.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/bend/GateWay.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/bend/man/ManCloud.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/bend/man/ManDB.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/config/BaseException.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/config/LoggerProxy.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/middle/ManGlobal.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/middle/ManModels.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/middle/models/CloudModels.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/fend/uimain/UiMain.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/helper/DbSqlite.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/helper/FileHelper.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/middle/signals/ManSignals.cpp
)

# 添加 UI 文件
set(UI_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/fend/uicom/uibasedialog.ui
    ${CMAKE_CURRENT_SOURCE_DIR}/fend/uicom/uibreadwidget.ui
    ${CMAKE_CURRENT_SOURCE_DIR}/fend/uicom/uimessagebox.ui
    ${CMAKE_CURRENT_SOURCE_DIR}/fend/uicom/uipagewidget.ui
    ${CMAKE_CURRENT_SOURCE_DIR}/fend/uicom/uiprogresswidget.ui
    ${CMAKE_CURRENT_SOURCE_DIR}/fend/uicom/uiqosdialog.ui
    ${CMAKE_CURRENT_SOURCE_DIR}/fend/uilogin/uilogindialog.ui
    ${CMAKE_CURRENT_SOURCE_DIR}/fend/uimain/uibucketslistwidget.ui
    ${CMAKE_CURRENT_SOURCE_DIR}/fend/uimain/uibucketstablewidget.ui
    ${CMAKE_CURRENT_SOURCE_DIR}/fend/uimain/uicreatebucketdialog.ui
    ${CMAKE_CURRENT_SOURCE_DIR}/fend/uimain/uimain.ui
    ${CMAKE_CURRENT_SOURCE_DIR}/fend/uimain/uiobjectstablewidget.ui
    ${CMAKE_CURRENT_SOURCE_DIR}/fend/uimain/uitoolbarwidget.ui
    ${CMAKE_CURRENT_SOURCE_DIR}/fend/uitransfer/uidownload.ui
    ${CMAKE_CURRENT_SOURCE_DIR}/fend/uitransfer/uitransfer.ui
    ${CMAKE_CURRENT_SOURCE_DIR}/fend/uitransfer/uiupload.ui
) 

# 添加资源文件
set(RESOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/resource.qrc
)

# 复制DLL文件到构建目录（确保运行时能找到）
file(COPY third/dll/libcrypto-1_1-x64.dll DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY third/dll/libssl-1_1-x64.dll DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY third/dll/PocoCrypto.dll DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY third/dll/PocoFoundation.dll DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY third/dll/PocoJSON.dll DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY third/dll/PocoNet.dll DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY third/dll/PocoNetSSL.dll DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY third/dll/PocoUtil.dll DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY third/dll/PocoXML.dll DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

# 创建可执行文件
add_executable(${PROJECT_NAME} ${SOURCES} ${UI_FILES} ${RESOURCES})

# 明确设置不创建窗口应用程序（即显示控制台）
set_target_properties(${PROJECT_NAME} PROPERTIES
    WIN32_EXECUTABLE FALSE  # 这是关键，确保设置为FALSE
)

# 链接 Qt 库
target_link_libraries(${PROJECT_NAME} Qt6::Core Qt6::Gui Qt6::Sql Qt6::Concurrent Qt6::Widgets)

# 设置库路径和链接库
if(WIN32)
    if(CMAKE_BUILD_TYPE STREQUAL "Release")
        target_link_directories(${PROJECT_NAME} PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/third/cos/libs/x64/
            ${CMAKE_CURRENT_SOURCE_DIR}/third/cos/third_party/lib/x64/poco/
        )
        target_link_libraries(${PROJECT_NAME} cossdk PocoFoundation)
    else()
        target_link_directories(${PROJECT_NAME} PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/third/cos/libs/x64/
            ${CMAKE_CURRENT_SOURCE_DIR}/third/cos/third_party/lib/x64/poco/
        )
        target_link_libraries(${PROJECT_NAME} cossdkd PocoFoundation)
    endif()
elseif(UNIX)
    target_link_directories(${PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/third/cos/libs/x64/
        ${CMAKE_CURRENT_SOURCE_DIR}/third/cos/third_party/lib/x64/poco/
    )
    target_link_libraries(${PROJECT_NAME} cossdk PocoFoundation)
endif()

# 设置应用程序图标（Windows）- 使用更可靠的方法
if(WIN32)
    set(APP_ICON ${CMAKE_CURRENT_SOURCE_DIR}/resource/imgs/logo.ico)
    if(EXISTS ${APP_ICON})
        # 创建一个 .rc 文件
        configure_file(
            ${CMAKE_CURRENT_SOURCE_DIR}/app_icon.rc.in
            ${CMAKE_CURRENT_BINARY_DIR}/app_icon.rc
        )
        
        # 添加资源文件到目标
        target_sources(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/app_icon.rc)
        
        # 设置可执行文件属性
        set_target_properties(${PROJECT_NAME} PROPERTIES
            WIN32_EXECUTABLE TRUE
            MACOSX_BUNDLE FALSE
        )
    endif()
endif()

# 安装目标（可选）
if(UNIX AND NOT APPLE AND NOT ANDROID)
    install(TARGETS ${PROJECT_NAME} DESTINATION /opt/${PROJECT_NAME}/bin)
elseif(QNX)
    install(TARGETS ${PROJECT_NAME} DESTINATION /tmp/${PROJECT_NAME}/bin)
endif()