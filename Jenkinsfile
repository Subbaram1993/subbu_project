pipeline {
    agent any

    tools {
        nodejs 'nodejs_v20.17.0'
    }

    stages {
        stage('Build') {
            steps {
                git branch: 'main', credentialsId: '9a6fcdd9-dd37-4c69-851a-0a16c1338cf1', url: 'https://github.com/Subbaram1993/subbu_project.git'
                bat 'copy E:\\subbu\\subbu_project\\package.json .'
                bat 'call "%NODE_HOME%\\nodevars.bat"'
                bat 'npm run build'
            }
        }
    }
}
