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

    post {
        success {
            // Update GitHub repository with build changes and ID
            git {
                remote {
                    name('origin')
                    url('https://github.com/Subbaram1993/subbu_project.git')
                    credentialsId('9a6fcdd9-dd37-4c69-851a-0a16c1338cf1')
                }
                branch('main')
            }
            sh "git add ."
            sh "git commit -m 'Updated build changes for Jenkins build #${BUILD_NUMBER}'"
            sh "git push origin main"
        }
    }
}
